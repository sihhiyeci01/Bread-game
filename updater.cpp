#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <filesystem>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <openssl/evp.h>

namespace fs = std::filesystem;
using json = nlohmann::json;

// libcurl write callback for file output
static size_t write_file(void* ptr, size_t size, size_t nmemb, void* userdata) {
    std::ofstream& out = *static_cast<std::ofstream*>(userdata);
    out.write(static_cast<char*>(ptr), size * nmemb);
    return size * nmemb;
}

// Download URL to local file
static bool download_url_to_file(const std::string& url, const fs::path& dst) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Error initializing curl for URL: " << url << std::endl;
        return false;
    }
    std::ofstream fout(dst, std::ios::binary);
    if (!fout) {
        std::cerr << "Error opening file for write: " << dst << std::endl;
        curl_easy_cleanup(curl);
        return false;
    }
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_file);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &fout);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "BreadUpdater");
    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    if (res != CURLE_OK) {
        std::cerr << "Curl error (" << res << ") downloading " << url << std::endl;
        return false;
    }
    return true;
}

// Compute SHA-256 of a file using OpenSSL EVP
static std::string sha256_of_file(const fs::path& path) {
    std::ifstream in(path, std::ios::binary);
    if (!in) {
        std::cerr << "Error opening file to hash: " << path << std::endl;
        return {};
    }
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    if (!ctx) {
        std::cerr << "Error creating EVP_MD_CTX" << std::endl;
        return {};
    }
    if (EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr) != 1) {
        std::cerr << "Error initializing digest" << std::endl;
        EVP_MD_CTX_free(ctx);
        return {};
    }
    char buffer[8192];
    while (in.read(buffer, sizeof(buffer))) {
        EVP_DigestUpdate(ctx, buffer, in.gcount());
    }
    if (in.gcount() > 0) {
        EVP_DigestUpdate(ctx, buffer, in.gcount());
    }
    unsigned char hashBuf[EVP_MAX_MD_SIZE];
    unsigned int len = 0;
    if (EVP_DigestFinal_ex(ctx, hashBuf, &len) != 1) {
        std::cerr << "Error finalizing digest" << std::endl;
        EVP_MD_CTX_free(ctx);
        return {};
    }
    EVP_MD_CTX_free(ctx);
    std::ostringstream os;
    os << std::hex << std::setw(2) << std::setfill('0');
    for (unsigned int i = 0; i < len; ++i) {
        os << (int)hashBuf[i];
    }
    return os.str();
}

// Terminate running process by executable name (ANSI)
bool terminate_process(const std::string& exeName) {
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(entry);
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) {
        std::cerr << "Failed to create process snapshot" << std::endl;
        return false;
    }
    bool found = false;
    if (Process32First(snapshot, &entry)) {
        do {
            if (_stricmp(entry.szExeFile, exeName.c_str()) == 0) {
                HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, entry.th32ProcessID);
                if (hProcess) {
                    TerminateProcess(hProcess, 0);
                    CloseHandle(hProcess);
                    found = true;
                }
            }
        } while (Process32Next(snapshot, &entry));
    }
    CloseHandle(snapshot);
    return found;
}

int main() {
    try {
        // Directories
        fs::path appDir = fs::path(std::getenv("LocalAppData")) / "Programs" / "Bread DEMO";
        fs::path tempDir = fs::path(std::getenv("TEMP")) / "BreadUpdater";
        fs::create_directories(tempDir);

        // 1) Fetch latest release metadata
        std::string apiUrl = "https://api.github.com/repos/sihhiyeci01/Bread-game/releases/latest";
        fs::path metaFile = tempDir / "release.json";
        if (!download_url_to_file(apiUrl, metaFile)) {
            std::cerr << "Error: could not fetch release metadata" << std::endl;
            return 1;
        }
        json release = json::parse(std::ifstream(metaFile));
        std::string version = release.value("tag_name", "");
        if (version.empty()) {
            std::cerr << "Error: tag_name missing in metadata" << std::endl;
            return 1;
        }

        // 2) Download remote manifest
        std::string manifestUrl;
        for (auto& asset : release["assets"]) {
            if (asset.value("name", "") == "manifest.json") {
                manifestUrl = asset.value("browser_download_url", "");
                break;
            }
        }
        if (manifestUrl.empty()) {
            std::cerr << "Error: manifest.json not found in release assets" << std::endl;
            return 1;
        }
        fs::path remoteManifest = tempDir / "manifest.json";
        if (!download_url_to_file(manifestUrl, remoteManifest)) {
            std::cerr << "Error: could not download manifest.json" << std::endl;
            return 1;
        }
        json remoteM = json::parse(std::ifstream(remoteManifest));

        // 3) Load local manifest or default
        fs::path localManifest = appDir / "manifest.json";
        json localM;
        if (fs::exists(localManifest)) {
            localM = json::parse(std::ifstream(localManifest));
        } else {
            localM = json::object({{"version","0.0.0"},{"files",json::array()}});
        }

        // 4) Map local hashes
        std::map<std::string, std::string> localHashes;
        for (auto& f : localM["files"]) {
            localHashes[f["path"].get<std::string>()] = f["hash"].get<std::string>();
        }

        // 5) Determine files to update
        struct FileEntry { std::string path, assetName, hash; };
        std::vector<FileEntry> toUpdate;
        for (auto& f : remoteM["files"]) {
            std::string p = f.value("path", "");
            std::string h = f.value("hash", "");
            std::string a = f.value("assetName", "");
            if (p.empty() || h.empty() || a.empty()) continue;
            if (!fs::exists(appDir / p) || localHashes[p] != h) {
                toUpdate.push_back({p, a, h});
            }
        }

        // 6) If no update needed, exit silently
        if (toUpdate.empty()) {
            std::cout << "No updates found; exiting." << std::endl;
            return 0;
        }

        // 7) Download and verify
        for (auto& fe : toUpdate) {
            fs::path dst = tempDir / fe.path;
            fs::create_directories(dst.parent_path());
            std::string url = "https://github.com/sihhiyeci01/Bread-game/releases/download/" + version + "/" + fe.assetName;
            std::cout << "Downloading " << fe.assetName << " from " << url << std::endl;
            if (!download_url_to_file(url, dst)) {
                std::cerr << "Error downloading " << fe.assetName << std::endl;
                return 1;
            }
            std::cout << "Computing SHA-256 for " << fe.assetName << std::endl;
            std::string fileHash = sha256_of_file(dst);
            if (fileHash.empty() || fileHash != fe.hash) {
                std::cerr << "Hash mismatch for " << fe.assetName << ": expected " << fe.hash << ", got " << fileHash << std::endl;
                return 1;
            }
        }

        // 8) Terminate running game
        std::cout << "Terminating running instances of Bread.exe..." << std::endl;
        terminate_process("Bread.exe");

        // 9) Replace files and update manifest
        for (auto& fe : toUpdate) {
            fs::path src = tempDir / fe.path;
            fs::path dst = appDir / fe.path;
            fs::create_directories(dst.parent_path());
            fs::rename(src, dst);
        }
        fs::rename(remoteManifest, localManifest);

        // 10) Restart the game once after update
        std::cout << "Restarting Bread.exe..." << std::endl;
        STARTUPINFOW si{};
        si.cb = sizeof(si);
        si.dwFlags = STARTF_USESHOWWINDOW;
        si.wShowWindow = SW_SHOW;
        PROCESS_INFORMATION pi;
        std::wstring gameExe = (appDir / "Bread.exe").wstring();
        BOOL launched = CreateProcessW(
            gameExe.c_str(), nullptr, nullptr, nullptr, FALSE,
            CREATE_NEW_CONSOLE, nullptr, nullptr, &si, &pi
        );
        if (!launched) {
            std::cerr << "Error launching updated game: " << GetLastError() << std::endl;
            return 1;
        }
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

        std::cout << "Update completed successfully." << std::endl;
        return 0;
    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return 1;
    }
}
