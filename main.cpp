#pragma comment(lib, "winmm.lib")
#define STB_IMAGE_IMPLEMENTATION
#define _WIN32_IE 0x0500	
#define OCR_NORMAL 32512
#ifndef SC_PROPERTIES
#define SC_PROPERTIES 0xF100
#endif
#include <algorithm>
#include <iostream>
#include <ShlObj.h>   
#include <cstdlib>
#include <cstdio> 
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>
#include <random>
#include <SFML/Audio.hpp>
#include <curl/curl.h>
#include <sstream>
#include <iomanip>
#include <SFML/Network.hpp>
#include <vector>
#include <atomic>
#include <iomanip>
#include <psapi.h>
#include <tlhelp32.h>
#include <mutex>
#include "stb_image.h"
#include "AudioManager.h"
#include <shellscalingapi.h>
//#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

string dosyaDynamicAnswer = "texts/dynamicAnswer.dat";

string dosyaWrap = "texts/wrap.dat";

string dosyaIsmi = "texts/1.dat";
		
string dosyaA = "texts/A.dat";
string dosyaAA = "texts/AA.dat";
string dosyaAAA = "texts/AAA.dat";
string dosyaAAAlocked = "texts/AAAlocked.dat";
string dosyaAAA2 = "texts/AAA2.dat";
string dosyaAAAA = "texts/AAAA.dat";
string dosyaAAAB = "texts/AAAB.dat";
string dosyaAAAC = "texts/AAAC.dat";
string dosyaAAAD = "texts/AAAD.dat";
string dosyaAAAD2 = "texts/AAAD2.dat";

string dosyaAAB = "texts/AAB.dat";

string dosyaAABA = "texts/AABA.dat";
string dosyaAABB = "texts/AABB.dat";
string dosyaAABC = "texts/AABC.dat";
string dosyaAABD = "texts/AABD.dat";

string dosyaAAC = "texts/AAC.dat";
string dosyaAAD = "texts/AAD.dat";
		
string dosyaAB = "texts/AB.dat";
string dosyaABA = "texts/ABA.dat";
string dosyaABAA = "texts/ABAA.dat";
string dosyaABAB = "texts/ABAB.dat";
string dosyaABAC = "texts/ABAC.dat";
string dosyaABAD = "texts/ABAD.dat";

string dosyaABB = "texts/ABB.dat";
string dosyaABBA = "texts/ABBA.dat";
string dosyaABBAA = "texts/ABBAA.dat";
string dosyaABBAB = "texts/ABBAB.dat";
string dosyaABBAC = "texts/ABBAC.dat";
string dosyaABBACA = "texts/ABBACA.dat";
string dosyaABBACB = "texts/ABBACB.dat";
string dosyaABBACC = "texts/ABBACC.dat";
string dosyaABBACD = "texts/ABBACD.dat";
string dosyaABBAD = "texts/ABBAD.dat";

string dosyaABBB = "texts/ABBB.dat";
string dosyaABBC = "texts/ABBC.dat";
string dosyaABBD = "texts/ABBD.dat";

string dosyaABC = "texts/ABC.dat";
string dosyaABCA = "texts/ABCA.dat";
string dosyaABCB = "texts/ABCB.dat";
string dosyaABCC = "texts/ABCC.dat";
string dosyaABCD = "texts/ABCD.dat";

string dosyaABD = "texts/ABD.dat";
string dosyaABDA = "texts/ABDA.dat";
string dosyaABDB = "texts/ABDB.dat";
string dosyaABDC = "texts/ABDC.dat";
string dosyaABDD = "texts/ABDD.dat";
		
string dosyaAC = "texts/AC.dat";
string dosyaACA = "texts/ACA.dat";
string dosyaACAA = "texts/ACAA.dat";
string dosyaACAB = "texts/ACAB.dat";
string dosyaACAC = "texts/ACAC.dat";
string dosyaACAD = "texts/ACAD.dat";

string dosyaACB = "texts/ACB.dat";
string dosyaACC = "texts/ACC.dat";
string dosyaACD = "texts/ACD.dat";
string dosyaACDA = "texts/ACDA.dat";
string dosyaACDB = "texts/ACDB.dat";
string dosyaACDC = "texts/ACDC.dat";
string dosyaACDD = "texts/ACDD.dat";
string dosyaACDDA = "texts/ACDDA.dat";
string dosyaACDDB = "texts/ACDDB.dat";
string dosyaACDDC = "texts/ACDDC.dat";
string dosyaACDDD = "texts/ACDDD.dat";

string dosyaACDDD2 = "texts/ACDDD2.dat";
string dosyaACDDDD2 = "texts/ACDDDD2.dat";
string dosyaACDDDDD = "texts/ACDDDDD.dat";
string dosyaACDDDDDD = "texts/ACDDDDDD.dat";
string dosyaACDDDDDDD = "texts/ACDDDDDDD.dat";
string dosyaACDDDDDDDD = "texts/ACDDDDDDDD.dat";
string dosyaACDDDDDDDDD = "texts/ACDDDDDDDDD.dat";

string dosyaACDDDA = "texts/ACDDDA.dat";
string dosyaACDDDB = "texts/ACDDDB.dat";
string dosyaACDDDC = "texts/ACDDDC.dat";
string dosyaACDDDD = "texts/ACDDDD.dat";

string dosyaACDDDAA = "texts/ACDDDAA.dat";
string dosyaACDDDAB = "texts/ACDDDAB.dat";
string dosyaACDDDAC = "texts/ACDDDAC.dat";

string dosyaACDDDAD = "texts/ACDDDAD.dat";
string dosyaACDDDADA = "texts/ACDDDADA.dat";
string dosyaACDDDADB = "texts/ACDDDADB.dat";
string dosyaACDDDADC = "texts/ACDDDADC.dat";

string dosyaACDDDADD = "texts/ACDDDADD.dat";
		
string dosyaAD = "texts/AD.dat";
string dosyaADA = "texts/ADA.dat";
string dosyaADAB = "texts/ADAB.dat";

string dosyaADB = "texts/ADB.dat";
string dosyaADC = "texts/ADC.dat";
string dosyaADD = "texts/ADD.dat";
		
string dosyaB = "texts/B.dat";
string dosyaBA = "texts/BA.dat";
string dosyaBAA = "texts/BAA.dat";
string dosyaBAB = "texts/BAB.dat";
string dosyaBABA = "texts/BABA.dat";
string dosyaBABD = "texts/BABD.dat";

string dosyaBAC = "texts/BAC.dat";
string dosyaBACA = "texts/BACA.dat";
string dosyaBACB = "texts/BACB.dat";

string dosyaBACC = "texts/BACC.dat";
string dosyaBACD = "texts/BACD.dat";
string dosyaBAD = "texts/BAD.dat";
		
string dosyaBB = "texts/BB.dat";
string dosyaBBA = "texts/BBA.dat";
string dosyaBBADD = "texts/BBADD.dat";
string dosyaBBAA = "texts/BBAA.dat";
string dosyaBBAB = "texts/BBAB.dat";
string dosyaBBABD = "texts/BBABD.dat";

string dosyaBBAC = "texts/BBAC.dat";
string dosyaBBAD = "texts/BBAD.dat";

string dosyaBBB = "texts/BBB.dat";
string dosyaBBBA = "texts/BBBA.dat";
string dosyaBBBB = "texts/BBBB.dat";
string dosyaBBBC = "texts/BBBC.dat";
string dosyaBBBD = "texts/BBBD.dat";

string dosyaBBC = "texts/BBC.dat";
string dosyaBBCA = "texts/BBCA.dat";
string dosyaBBCB = "texts/BBCB.dat";
string dosyaBBCC = "texts/BBCC.dat";
string dosyaBBCD = "texts/BBCD.dat";

string dosyaBBD = "texts/BBD.dat";
string dosyaBBDA = "texts/BBDA.dat";
string dosyaBBDB = "texts/BBDB.dat";
string dosyaBBDC = "texts/BBDC.dat";
string dosyaBBDD = "texts/BBDD.dat";
		
string dosyaBC = "texts/BC.dat";
string dosyaBCA = "texts/BCA.dat";
string dosyaBCAA = "texts/BCAA.dat";
string dosyaBCAB = "texts/BCAB.dat";
string dosyaBCAC = "texts/BCAC.dat";
string dosyaBCAD = "texts/BCAD.dat";

string dosyaBCB = "texts/BCB.dat";
string dosyaBCBA = "texts/BCBA.dat";
string dosyaBCBB = "texts/BCBB.dat";
string dosyaBCBC = "texts/BCBC.dat";
string dosyaBCBD = "texts/BCBD.dat";

string dosyaBCC = "texts/BCC.dat";
string dosyaBCCA = "texts/BCCA.dat";
string dosyaBCCB = "texts/BCCB.dat";

string dosyaBCD = "texts/BCD.dat";
		
string dosyaBD = "texts/BD.dat";
	
string dosyaC = "texts/C.dat";
string dosyaCA = "texts/CA.dat";
string dosyaCACA = "texts/CACA.dat";

string dosyaCAA = "texts/CAA.dat";
string dosyaCAAA = "texts/CAAA.dat";
string dosyaCAAB = "texts/CAAB.dat";
string dosyaCAAC = "texts/CAAC.dat";
string dosyaCAAD = "texts/CAAD.dat";

string dosyaCAB = "texts/CAB.dat";
string dosyaCABA = "texts/CABA.dat";
string dosyaCABB = "texts/CABB.dat";
string dosyaCABC = "texts/CABC.dat";
string dosyaCABD = "texts/CABD.dat";

string dosyaCAC = "texts/CAC.dat";
string dosyaCAD = "texts/CAD.dat";
string dosyaCACD = "texts/CACD.dat";
string dosyaCACDA = "texts/CACDA.dat";
string dosyaCACDB = "texts/CACDB.dat";
string dosyaCACDBD = "texts/CACDBD.dat";
string dosyaCB = "texts/CB.dat";
string dosyaCBA = "texts/CBA.dat";
string dosyaCBAA = "texts/CBAA.dat";
string dosyaCBAB = "texts/CBAB.dat";
string dosyaCBAC = "texts/CBAC.dat";
string dosyaCBAD = "texts/CBAD.dat";

string dosyaCBB = "texts/CBB.dat";

string dosyaCBC = "texts/CBC.dat";
string dosyaCBCC = "texts/CBCC.dat";
string dosyaCBCB = "texts/CBCB.dat";
string dosyaCBCD = "texts/CBCD.dat";

string dosyaCBD = "texts/CBD.dat";
string dosyaCBDC = "texts/CBDC.dat";
string dosyaCBDD = "texts/CBDD.dat";
		
string dosyaCC = "texts/CC.dat";
string dosyaCCA = "texts/CCA.dat";
string dosyaCCAA = "texts/CCAA.dat";
string dosyaCCAB = "texts/CCAB.dat";
string dosyaCCAC = "texts/CCAC.dat";
string dosyaCCAD = "texts/CCAD.dat";

string dosyaCCB = "texts/CCB.dat";
string dosyaCCBA = "texts/CCBA.dat";
string dosyaCCBC = "texts/CCBC.dat";

string dosyaCCC = "texts/CCC.dat";
string dosyaCCCC = "texts/CCCC.dat";

string dosyaCCD = "texts/CCD.dat";
string dosyaCCDA = "texts/CCDA.dat";
string dosyaCCDB = "texts/CCDB.dat";
string dosyaCCDC = "texts/CCDC.dat";

string dosyaCCDD = "texts/CCDD.dat";
string dosyaCCDDA = "texts/CCDDA.dat";
string dosyaCCDDB = "texts/CCDDB.dat";
string dosyaCCDDC = "texts/CCDDC.dat";
		
string dosyaCD = "texts/CD.dat";
	
string dosyaD = "texts/D.dat";

string dosyaUnlock = "texts/Unlock.dat";
string dosyaOffensiveUnlock = "texts/OffensiveUnlock.dat";
string dosyaConnect = "texts/Connect.dat";
string dosyaDisconnect = "texts/Disconnect.dat";

string dosyaDisconnect2 = "texts/Disconnect2.dat";
string dosyaConnect2 = "texts/Connect2.dat";

string fileNameControl = "NULL";
string PCname;
string content;

struct TypedChar {
    char ch;
    int delayMs;
    bool isBackspace;
}; 
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    return size * nmemb;  // Veriyi yutuyoruz, hiçbir işlem yapmıyoruz
}
size_t musicThread(std::wstring path) {
    sf::Music music;
    if (!music.openFromFile(std::string(path.begin(), path.end())))
        return 0;

    music.play();
    while (music.getStatus() == sf::Music::Playing)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    return 1;
}


const char XOR_KEY = 0x5A;
const char* shades = " .:-=+*#%@";  

string readConsoleRegion(int x, int y, int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string result;

    for (int row = 0; row < height; ++row) {
        DWORD charsRead = 0;
        CHAR buffer[256] = { 0 };  // En fazla 256 karakter oku
        COORD coord = { (SHORT)x, (SHORT)(y + row) };

        ReadConsoleOutputCharacterA(
            hConsole,
            buffer,
            width,
            coord,
            &charsRead
        );

        result.append(buffer, charsRead);
        result.push_back('\n');  // Satır sonu
    }

    return result;
}
string readXorEncryptedFileToString(const string& filePath) {
    ifstream in(filePath, ios::binary);
    if (!in) {
        cerr << "Dosya açılamadı: " << filePath << endl;
        return "";
    }

    // Dosya içeriğini oku
    vector<char> buffer((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());

    // XOR ile çöz
    for (char& byte : buffer) {
        byte ^= XOR_KEY;
    }

    // string'e dönüştür
    return string(buffer.begin(), buffer.end());
}
string urlEncode(const std::string& value) {
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;

    for (char c : value) {
        if (isalnum(static_cast<unsigned char>(c)) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
        } else {
            escaped << '%' << std::uppercase << std::setw(2) << int((unsigned char)c);
        }
    }

    return escaped.str();
}
string getComputerName() {
    char computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computerName);
    if (GetComputerNameA(computerName, &size)) {
        return std::string(computerName);
    }
    return "BILINMEYEN_CIHAZ";
}
string getDesktopPath() {
    char path[MAX_PATH];
    SHGetFolderPathA(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, path);
    return std::string(path);
}

void cerrText(const string& text, bool centerVertically = true) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    int screenWidth = csbi.dwSize.X;
    int screenHeight = csbi.dwSize.Y - 2;

    int x = max(0, (screenWidth - static_cast<int>(text.length())) / 2);
    int y = centerVertically ? screenHeight / 2 : csbi.dwCursorPosition.Y;

    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(hConsole, pos);

    cerr << text;
}

int s;
int progress;
int zikkim = 0;
int loopRepeat = 0;
int cursorLimit = 3;
int zikkiminkoku = 0;
const int outputWidth = 100;    

bool gameFinished = false;
bool AAADlock = true;
bool ACDDDloop = false;
bool portDeleted = false;
bool isInChat = false;
bool isMainMenu = false;
bool isFullSizeMode = false;
bool offensiveAnswersLocked = true;
bool breadsEncryptedPort = false;
bool setConsoleSize(short width, short height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) return false;

    // 1) Maksimum izin verilen pencere boyutunu al, clamp et
    COORD maxSize = GetLargestConsoleWindowSize(hConsole);
    width  = min<SHORT>(width,  maxSize.X);
    height = min<SHORT>(height, maxSize.Y);

    // 2) Pencereyi en küçüğe çek
    SMALL_RECT minimalRect = {0, 0, 1, 1};
    if (!SetConsoleWindowInfo(hConsole, TRUE, &minimalRect)) return false;

    // 3) Tamponu ayarla
    COORD newSize = { width, height };
    if (!SetConsoleScreenBufferSize(hConsole, newSize)) return false;

    // 4) Pencere boyutunu ayarla
    SMALL_RECT windowRect = {0, 0, static_cast<SHORT>(width - 1), static_cast<SHORT>(height - 1)};
    if (!SetConsoleWindowInfo(hConsole, TRUE, &windowRect)) return false;

    // 5) Scrollbar’ları gizle
    HWND hwnd = GetConsoleWindow();
    if (hwnd) {
        // SB_BOTH, yatay ve dikey çubukları birlikte gizler
        ShowScrollBar(hwnd, SB_BOTH, FALSE);
    }

    return true;
}
bool loadSound(const std::string& filepath, sf::SoundBuffer& buffer, sf::Sound& sound) {
	if(!buffer.loadFromFile(filepath)){
		system("cls");
		cerrText("Failed to open file...\n\n");
		cerrText("\b\b\b\b\b\b\b\b\b\bFile : ", false );
		cerr << filepath << endl << endl;
		cerrText("\bReinstall the local files!", false);
		this_thread::sleep_for(chrono::seconds(10));
		exit(0);
	}
	sound.setBuffer(buffer);
	return true;
}
bool isBreadWindowOpen() {
    bool found = false;
    EnumWindows([](HWND hwnd, LPARAM lParam) -> BOOL {
        wchar_t title[256];
        GetWindowTextW(hwnd, title, sizeof(title) / sizeof(wchar_t));
        std::wstring windowTitle(title);
        if (windowTitle == L"Bread") {
            *reinterpret_cast<bool*>(lParam) = true;
            return FALSE;
        }
        return TRUE;
    }, reinterpret_cast<LPARAM>(&found));
    return found;
}
bool captureScreenshotToDesktop() {
    int x = GetSystemMetrics(SM_XVIRTUALSCREEN);
    int y = GetSystemMetrics(SM_YVIRTUALSCREEN);
    int width = GetSystemMetrics(SM_CXVIRTUALSCREEN);
    int height = GetSystemMetrics(SM_CYVIRTUALSCREEN);

    HDC hScreenDC = GetDC(NULL);
    HDC hMemoryDC = CreateCompatibleDC(hScreenDC);

    HBITMAP hBitmap = CreateCompatibleBitmap(hScreenDC, width, height);
    HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemoryDC, hBitmap);

    BitBlt(hMemoryDC, 0, 0, width, height, hScreenDC, x, y, SRCCOPY);
    SelectObject(hMemoryDC, hOldBitmap);

    BITMAP bmp;
    GetObject(hBitmap, sizeof(BITMAP), &bmp);

    BITMAPFILEHEADER bmfHeader;
    BITMAPINFOHEADER bi;

    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = bmp.bmWidth;
    bi.biHeight = -bmp.bmHeight; // negatif = top-down DIB
    bi.biPlanes = 1;
    bi.biBitCount = 32;
    bi.biCompression = BI_RGB;
    bi.biSizeImage = 0;
    bi.biXPelsPerMeter = 0;
    bi.biYPelsPerMeter = 0;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;

    DWORD bmpSize = bmp.bmWidth * bmp.bmHeight * 4;
    std::vector<BYTE> bmpData(bmpSize);

    GetDIBits(hMemoryDC, hBitmap, 0, bmp.bmHeight, bmpData.data(), (BITMAPINFO*)&bi, DIB_RGB_COLORS);

    std::string path = getDesktopPath() + "\\Congratulations!.bmp";

    std::ofstream file(path, std::ios::out | std::ios::binary);
    if (!file.is_open()) return false;

    bmfHeader.bfType = 0x4D42;
    bmfHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bmpSize;
    bmfHeader.bfReserved1 = 0;
    bmfHeader.bfReserved2 = 0;
    bmfHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    file.write((char*)&bmfHeader, sizeof(bmfHeader));
    file.write((char*)&bi, sizeof(bi));
    file.write((char*)bmpData.data(), bmpSize);
    file.close();

    DeleteObject(hBitmap);
    DeleteDC(hMemoryDC);
    ReleaseDC(NULL, hScreenDC);

    return true;
}

static SoundBuffer mainmenu1, mainmenu, theme, mysteryTheme, effect2, effect3, effect4, effect5, effect6, effect7, effect8, effect10, effect11, effect12, effect13, effect14, effect15, effect16, effect17, effect18, effect19, disconnected, effect, theMusic, theUnknownPort, breadmusic7, effect20, effect21, effect22, effect23, effect24, effect25, effect26, effect27, effect28, effect29, music1, music2, darktheme1, breadmusic11, effect30, breadmusic13, hek, breadmusic14;
static Sound Opening, mainTheme, theme1, theme2, welcomeEffect, fallEffect, fallEffect2, clickEffect, breadDisconnected, breadEffect, youEffect, theProgrammerEffect, systemEffect, answerEffect, connectionEffect, theJohnDensmore, UnknownPort, love, keyhit, enterhit, chathit, validhit, backspacehit, key1, key2, key3, space1, space2, space3, backspace1, backspace2, backspace3, enter, pitchtheme1, pitchtheme2, darktheme, abba, clickEffect2, bach, hello, finalCall;

COORD position;
COORD cursorPosition;
COORD cursorPosition2;
COORD startPosition;
COORD getCursorPosition() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Konsol çıktısı tutamacını al
    CONSOLE_SCREEN_BUFFER_INFO csbi;                   // Bilgiyi saklamak için yapı

    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) { // Bilgiyi al
        return csbi.dwCursorPosition; // X ve Y koordinatlarını döndür
    } else {
        // Hata olursa varsayılan (0,0) döndür
        return {0, 0};
    }
}

atomic<bool> pressed{ false };
atomic<bool> returnToMenu(false);
atomic<bool> isDrawingMenu(false);
atomic<bool> isThreadRunning(false);
atomic<bool> isDragging(false);
atomic<bool> isLeftButtonDown(false); 
atomic<bool> breadSystemRunning{ false };
atomic<bool> g_running{ true };
atomic<bool> isEventMouse{ false };

vector<TypedChar> loadFromFile(const string& filename) {
    ifstream in(filename);
    vector<TypedChar> buffer;
    string line;

    if (!in.is_open()) {
        cerr << "Dosya açılamadı: " << filename << "\n";
        return {};
    }

    while (getline(in, line)) {
        if (line.empty()) continue;
        string key = line.substr(0, line.find(' '));
        int delay = stoi(line.substr(line.find(' ') + 1));

        char actualChar;
        bool isBackspace = false;
		
        if (key == "\\b") {
            actualChar = '\b';
            isBackspace = true;
        } else if (key == "space") {
            actualChar = ' ';
        } else if (key=="enter") {
			actualChar = '#';
		} else {
            actualChar = key[0];
        }

        buffer.push_back({actualChar, delay, isBackspace});
    }

    return buffer;
}

HHOOK g_hMouseHook = nullptr;	
HHOOK keyboardHook = nullptr;
HHOOK mouseHook = nullptr;

LRESULT CALLBACK aKeyboardProcs(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        KBDLLHOOKSTRUCT* pKeyboard = (KBDLLHOOKSTRUCT*)lParam;
        return 1;
    }
    return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}
LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        switch (wParam) {
            case WM_LBUTTONDOWN:
            case WM_LBUTTONUP:
            case WM_RBUTTONDOWN:
            case WM_RBUTTONUP:
            case WM_MBUTTONDOWN:
            case WM_MBUTTONUP:
            case WM_MOUSEWHEEL:
            case WM_MOUSEHWHEEL:
                return 1; 
            default:
                break; // Hareket gibi diğer olaylara dokunma
        }
    }
    return CallNextHookEx(mouseHook, nCode, wParam, lParam);
}
LRESULT CALLBACK LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        HWND fg = GetForegroundWindow();
        HWND me = GetConsoleWindow(); 
        if (fg != me) 
            return CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);

        switch (wParam) {
            case WM_RBUTTONDOWN:
                isEventMouse.store(true);
                isLeftButtonDown.store(false);
                break;
            case WM_LBUTTONDOWN:
                isEventMouse.store(true);
                isLeftButtonDown.store(true);
                break;
        }
    }
    return CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
}


void disableQuickEditAndEnableMouseInput() {
    HWND hwnd = GetConsoleWindow();
    if (!hwnd) return;

    HMENU hMenu = GetSystemMenu(hwnd, FALSE);
    if (!hMenu) return;

    // SC_PROPERTIES = Özellikler menü komutu
    RemoveMenu(hMenu, SC_PROPERTIES, MF_BYCOMMAND);
    DrawMenuBar(hwnd);
}
void disableConsoleHotkeys() {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    if (GetConsoleMode(hInput, &mode)) {
        mode &= ~ENABLE_WINDOW_INPUT;
        mode &= ~ENABLE_PROCESSED_INPUT;
        SetConsoleMode(hInput, mode);
    }
}
void BreadSystem() {
    breadSystemRunning = true;
    std::vector<int> sequence = { 'B', 'R', 'E', 'A', 'D' };
    int currentIndex = 0;

    disableConsoleHotkeys();

    // Klavye Hook
    keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL,
        [](int nCode, WPARAM wParam, LPARAM lParam) -> LRESULT {
            static std::vector<int> sequence = { 'B', 'R', 'E', 'A', 'D' };
            static int currentIndex = 0;

            if (nCode == HC_ACTION && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)) {
                HWND activeWnd = GetForegroundWindow();
                HWND consoleWnd = GetConsoleWindow();
                if (activeWnd != consoleWnd)
                    return CallNextHookEx(NULL, nCode, wParam, lParam);

                KBDLLHOOKSTRUCT* kb = (KBDLLHOOKSTRUCT*)lParam;

                bool altPressed = (GetAsyncKeyState(VK_MENU) & 0x8000);
                if (altPressed && kb->vkCode == VK_RETURN) return 1;
                if (kb->vkCode == VK_F11) return 1;

                int key = kb->vkCode;
                bool ctrlPressed = (GetAsyncKeyState(VK_CONTROL) & 0x8000);

                if (ctrlPressed && altPressed) {
                    if (key == sequence[currentIndex]) {
                        currentIndex++;
                        if (currentIndex == (int)sequence.size()) {
                            SML::PlayFileOnce("breadmusic12.mp3");
                            currentIndex = 0;
                        }
                    } else {
                        currentIndex = 0;
                    }
                } else {
                    currentIndex = 0;
                }
            }

            return CallNextHookEx(NULL, nCode, wParam, lParam);
        }, NULL, 0);

    if (!keyboardHook) {
        breadSystemRunning = false;
        return;
    }

    // Fare Hook
    mouseHook = SetWindowsHookEx(WH_MOUSE_LL,
        [](int nCode, WPARAM wParam, LPARAM lParam) -> LRESULT {
            if (nCode == HC_ACTION) {
                HWND activeWnd = GetForegroundWindow();
                HWND consoleWnd = GetConsoleWindow();
                if (activeWnd != consoleWnd)
                    return CallNextHookEx(NULL, nCode, wParam, lParam);

                if (wParam == WM_RBUTTONDOWN || wParam == WM_RBUTTONUP) {
                    return 1; // Sağ tık engelleniyor
                }
            }
            return CallNextHookEx(NULL, nCode, wParam, lParam);
        }, NULL, 0);

    if (!mouseHook) {
        UnhookWindowsHookEx(keyboardHook);
        breadSystemRunning = false;
        return;
    }

    // Windows mesaj döngüsü (hook'lar için gerekli)
    MSG msg;
    while (breadSystemRunning) {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                breadSystemRunning = false;
                break;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    // Hook'ları temizle
    UnhookWindowsHookEx(mouseHook);
    UnhookWindowsHookEx(keyboardHook);
}
void sendTwilioCall() {
    const std::string account_sid = "AC58aaacb6bdffac5ef0a16599a09b9e68";
    const std::string auth_token = "634f62a003eb6607b2a98d392582053b";
    const std::string to_number = "+905386418990";
    const std::string from_number = "+12678132514";
    const std::string twiml_url = "https://hello-5764.twil.io/hello";

    CURL* curl = curl_easy_init();
    if (!curl) return;

    std::string computerName = getComputerName();
    std::string full_url = twiml_url + "?name=" + computerName;
    std::string encodedUrl = urlEncode(full_url);

    std::string postData =
        "To=" + urlEncode(to_number) + "&" +
        "From=" + urlEncode(from_number) + "&" +
        "Url=" + encodedUrl;

    std::string url = "https://api.twilio.com/2010-04-01/Accounts/" + account_sid + "/Calls";

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_USERPWD, (account_sid + ":" + auth_token).c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
}
void centerText(const string& text, bool centerVertically = true) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    int screenWidth = csbi.dwSize.X;
    int screenHeight = csbi.dwSize.Y;

    int x = max(0, (screenWidth - static_cast<int>(text.length())) / 2);
    int y = centerVertically ? screenHeight / 2 : csbi.dwCursorPosition.Y;

    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(hConsole, pos);

    cout << text;
}
void hookThread() {
    HINSTANCE hInstance = GetModuleHandle(nullptr);

    keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, aKeyboardProcs, hInstance, 0);
    mouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseProc, hInstance, 0);

    if (!keyboardHook || !mouseHook) {
        std::cerr << "Hook kurulamadı!" << std::endl;
        return;
    }

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(keyboardHook);
    UnhookWindowsHookEx(mouseHook);
}
void printImageAsASCII(const char* filename) {
    int width, height, channels;
    unsigned char* img = stbi_load(filename, &width, &height, &channels, 1); // grayscale olarak yükle

    if (!img) {
        cerr << "Görsel yüklenemedi!\n";
        return;
    }

    int scale = width / outputWidth;
    int outputHeight = height / (scale * 2); // Yaklaşık satır sayısı
    string output;
    output.reserve(outputWidth * outputHeight + outputHeight); // Performans için hafızayı önceden al

    for (int y = 0; y < height; y += scale * 2) {
        for (int x = 0; x < width; x += scale) {
            int pixelIndex = y * width + x;
            unsigned char pixel = img[pixelIndex];
            int shadeIndex = (pixel * 10) / 256; // 0-255 → 0-9 arası
            output += shades[shadeIndex];
        }
        output += '\n';
    }

    stbi_image_free(img);

    // Tek seferde yazdır (çok daha hızlı!)
    fwrite(output.c_str(), 1, output.size(), stdout);
}
void setAyar() {
    ifstream file("ayar.dat");

    if (!file) {
        cerr << "ayar.dat dosyası bulunamadı!" << endl;
        return;  // Hata durumunda fonksiyonu sonlandır
    }

    int deger;
    file >> deger;
    file.close();  // Dosyayı kapatıyoruz

    // Yeni bir değer belirleyelim
    int yeniDeger = 1;  // Değiştirmek istediğimiz yeni sayı

    // Şimdi dosyayı yazma (write) modunda açıyoruz
    ofstream outputFile("ayar.dat");  // Bu işlem mevcut dosyanın içeriğini sıflar
    if (!outputFile) {
        cerr << "Dosya açılamadı!" << endl;
        return;  // Hata durumunda fonksiyonu sonlandır
    }

    // Yeni değeri dosyaya yazıyoruz
    outputFile << yeniDeger;
    outputFile.close();  // Dosyayı kapatıyoruz

    cout << "Yeni değer '" << yeniDeger << "' yazıldı!" << endl;
}
void setTextColor(WORD foregroundColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Mevcut renk bilgilerini al
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    // Arka plan rengini koru, ön plan rengini değiştir
    WORD bgColor = csbi.wAttributes & 0xF0; // Arka plan kısmı (high nibble)
    WORD newColor = bgColor | (foregroundColor & 0x0F); // Ön plan kısmı (low nibble)

    SetConsoleTextAttribute(hConsole, newColor);
}
void clearInputBuffer() {
    // Klavye tamponundaki tuşları temizle
    while (_kbhit()) {
        _getch();  // Tampondaki tüm tuşları al ve yok say
    }
}
void setConsoleToNonQuickEditMode() {
    HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);
    DWORD dwMode;

    if (GetConsoleMode(hConsole, &dwMode)) {
        dwMode &= ~ENABLE_QUICK_EDIT_MODE;  // QuickEdit'i devre dışı bırak
        SetConsoleMode(hConsole, dwMode);
    }
}
void renklendir(int x, int y, int uzunluk, int yeniOnPlanRengi) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { (SHORT)x, (SHORT)y };
    DWORD charsRead = 0;
    DWORD charsWritten = 0;

    // Mevcut renk özniteliklerini oku
    WORD* mevcutRenkler = new WORD[uzunluk];
    if (!ReadConsoleOutputAttribute(hConsole, mevcutRenkler, uzunluk, coord, &charsRead) || charsRead != (DWORD)uzunluk) {
        // Hata durumunda temizle ve çık
        delete[] mevcutRenkler;
        return;
    }

    // Her bir renkte sadece ön plan rengini değiştir, arka planı koru
    for (int i = 0; i < uzunluk; ++i) {
        WORD bg = mevcutRenkler[i] & 0xF0;            // Arka plan rengini al
        WORD fg = yeniOnPlanRengi & 0x0F;             // Yeni ön plan rengi
        mevcutRenkler[i] = bg | fg;                    // Kombine et
    }

    // Yeni renkleri yaz
    WriteConsoleOutputAttribute(hConsole, mevcutRenkler, uzunluk, coord, &charsWritten);

    delete[] mevcutRenkler;
}
void dosyaGonder() {
    // %APPDATA% yolunu al
    const char* appdataPath = getenv("APPDATA");
    if (!appdataPath) {
        cerr << "APPDATA yolunu alamıyorum!" << endl;
        return;
    }

    // Dosya yolunu oluştur
    string dosyaYolu = string(appdataPath) + "\\pathInfo.dat";

    // Dosyayı aç
    ifstream dosya(dosyaYolu, ios::in);
    if (!dosya.is_open()) {
        cerr << "HATA: Dosya açılamadı! (" << dosyaYolu << ")" << endl;
        return;
    }

    // Dosya içeriğini oku
    string dosyaIcerigi((istreambuf_iterator<char>(dosya)), istreambuf_iterator<char>());
    
    // Windows bilgisayar ismini al
    char bilgisayarAdi[256];
    DWORD uzunluk = sizeof(bilgisayarAdi);
    if (!GetComputerNameA(bilgisayarAdi, &uzunluk)) {
        cerr << "Bilgisayar ismi alınamadı!" << endl;
        return;
    }
    string pcIsmi = string(bilgisayarAdi);
	PCname = string(bilgisayarAdi);
    // Sunucuya bağlanacak TCP soketi oluşturuluyor
    sf::TcpSocket socket;
    string sunucuIP = "192.168.0.19";  // Buraya sunucunun IP adresini yaz

    if (socket.connect(sunucuIP, 54000) != sf::Socket::Done) {
        //cerr << "NETWORK ERROR! Sunucuya bağlanılamadı!" << endl;
        return;
    }

    // Gönderilecek verinin boş olup olmadığını kontrol et
    if (dosyaIcerigi.empty()) {
        cerr << "UYARI: Gönderilecek veri boş!" << endl;
        return;
    }

    // Bilgisayar ismini ve dosya içeriğini birleştiriyoruz
    string veri = "PC Adı: " + pcIsmi + "\n\n" + "Dosya İçeriği:\n" + dosyaIcerigi;

    // Veri gönderme kısmı: Yeniden deneme ekleyelim
    bool gonderildi = false;
    int denemeSayisi = 0;
    while (denemeSayisi < 5 && !gonderildi) {
        if (socket.send(veri.c_str(), veri.size()) == sf::Socket::Done) {
            gonderildi = true;  // Veri başarıyla gönderildi
        } else {
            cerr << "Veri gönderimi başarısız oldu, yeniden deniyorum... (" << denemeSayisi + 1 << "/5)" << endl;
            denemeSayisi++;
            this_thread::sleep_for(chrono::seconds(1));  // 1 saniye bekle ve yeniden dene
        }
    }

    if (gonderildi) {
        cout << "Veri başarıyla gönderildi!" << endl;
    } else {
        cerr << "Veri gönderimi 5 denemede de başarısız oldu." << endl;
    }

    return;
}
void moveCursorRelative(int deltaX, int deltaY) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    
    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        COORD newPos;
        newPos.X = csbi.dwCursorPosition.X + deltaX;
        newPos.Y = csbi.dwCursorPosition.Y + deltaY;

        // Negatif veya ekran dışına çıkmayı engelle
        if (newPos.X < 0) newPos.X = 0;
        if (newPos.Y < 0) newPos.Y = 0;

        SetConsoleCursorPosition(hConsole, newPos);
    }
}
void randomWaitInRange(int minMs, int maxMs) {
		// Rastgele sayı üretici
		random_device rd;
		mt19937 gen(rd()); // Mersenne Twister algoritması
		uniform_int_distribution<> dist(minMs, maxMs);

		// Rastgele süreyi belirle
		int waitTime = dist(gen);

		// Bekleme işlemi
		this_thread::sleep_for(chrono::milliseconds(waitTime));
	}
void hideCursor() {
    // Konsol ekranını al
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    
    // İmleç bilgi yapısını ayarla
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false; // İmleci görünmez yap
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
void showCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = TRUE; // Kursör görünürlüğünü aç
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
void moveCursor(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) }; // (x, y) koordinatları
    SetConsoleCursorPosition(hConsole, pos);
	}
void clearArea(int x, int y, int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD written;
    COORD coord;

    string blankLine(width, ' '); // Tek satırlık boş karakter dizisi

    for (int i = 0; i < height; ++i) {
        coord.X = x;
        coord.Y = y + i;
        WriteConsoleOutputCharacterA(hConsole, blankLine.c_str(), width, coord, &written);
    }
}
void setConsoleFont(const wstring& fontName, int fontSize) {
    // Konsol pencere tanıtıcısını (handle) al
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Font bilgilerini içeren yapı
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);

    // Mevcut font bilgilerini al
    GetCurrentConsoleFontEx(hConsole, FALSE, &cfi);

    // Font ismini ve boyutunu ayarla
    wcscpy_s(cfi.FaceName, fontName.c_str()); // Yazı tipi ismi
    cfi.dwFontSize.X = 0;                     // Genişlik (otomatik ayar için 0 bırakılabilir)
    cfi.dwFontSize.Y = fontSize;              // Yükseklik (yazı boyutu)

    // Yeni font ayarlarını uygula
    SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}
void saveDecryptedTextToTempFile(const string& text, const string& filePath) {
    ofstream out(filePath, ios::binary);  // ← önemli
    if (!out) {
        cerr << "Dosya yazılamadı: " << filePath << endl;
        return;
    }
    out.write(text.data(), text.size());
}
void bilmemne(int vrgl, int nkt, int nktvrgl, int unlm, int sr, int inkt, const string& dosyaAdi){
	char* appdataPath = std::getenv("APPDATA");
    if (!appdataPath) return; // APPDATA yoksa çık

    std::string progressPath = std::string(appdataPath) + "\\progress.dat";

    std::ifstream inFile(progressPath);
    if (!inFile.is_open()) return; 

    ostringstream buffer;
    buffer << inFile.rdbuf();
    string content = buffer.str();

    if (content.find(dosyaAdi) == string::npos) {
        ofstream outFile(progressPath, ios::app);

		outFile << dosyaAdi << "\n";
    }
	
	ifstream dosya;
	
	if (dosyaAdi != "texts/dynamicAnswer.dat") {
		string cleanText = readXorEncryptedFileToString(dosyaAdi);
		saveDecryptedTextToTempFile(cleanText, "texts/temp_decrypted.dat");
		dosya.open("texts/temp_decrypted.dat");
	} else {
		dosya.open(dosyaAdi);
	}

	char current, next;
	dosya.get(current);
	
	fileNameControl = dosyaAdi;
	 
	int kts = 0;
	int cc = 0;
	int i = 0;
	int s = 0;
	int z = 0;
	int tk = 0;
	int endl = 0;
	int dd = 0;
	int konusan = 0;
	int aptalonay = 0;
	int satirboslugu = 0;
	int porno = 0;
	bool permisson = true;
	wchar_t ch = L'—';
	
	
	if(dosyaAdi!="texts/Connect.dat"&&dosyaAdi!="texts/Disconnect.dat"&&dosyaAdi!="texts/1.dat"&&zikkim==0){
		moveCursor(startPosition.X+1, startPosition.Y-1);
	}
	if(zikkim==1){
		moveCursor(startPosition.X+1, startPosition.Y+3);
		zikkim = 0;
	}
	if(dosyaAdi=="texts/Unlock.dat"||dosyaAdi=="texts/OffensiveUnlock.dat"){
		moveCursor(startPosition.X-2, startPosition.Y-1);
		zikkim = 1;
	}
	if(dosyaAdi=="texts/Disconnect.dat"){
		moveCursor(cursorPosition.X, cursorPosition.Y);
		moveCursorRelative(+5, +1);
	}
	
	SML::LoadEffect("bread", "sound/effect/effect.wav");
	SML::LoadEffect("you", "sound/effect/effect2.wav");
	SML::LoadEffect("system", "sound/effect/effect7.wav");
	SML::LoadEffect("connection", "sound/effect/effect3.wav");
	
	while(dosya.get(next)){
		if(cc!=1||current != ' '){
			cout << current;
		} else {
			cc--;
		}
		
		if(current=='"'){
			tk ++;
			kts ++;
		}
		if(current=='\n'){
			cc = 0;
			endl++;
		}
		if(current==':'){
			dd ++;
		}
		
		
		if(kts%2!=0&&kts!=0){
			if(cc==90){
				cout <<"\n               ";
				cc = 0;
			}
			cc++;
		}
		
		
		if(current!='.'&&current!=','&&current!='!'&&current!='?'&&current!=' '&&current!='"'&&current!=';'&&current!=10&&current!='-'&&current!=L'—'){
			switch (konusan) {
				case 1:
					SML::PlayEffect("bread", false, 40.f);
					break;
					
				case 2:
					SML::PlayEffect("you", false, 40.f);
					break;
				case 3:
					SML::PlayEffect("system", false, 80.f);
					break; 
			}
		}
		
		if(next!='"'&&(konusan==1||konusan==4)){
			switch (current) {
				case '.':
					this_thread::sleep_for(chrono::milliseconds(nkt));
					break;
					
				case ',':
					this_thread::sleep_for(chrono::milliseconds(vrgl));
					break;
					
				case ';':
					this_thread::sleep_for(chrono::milliseconds(nktvrgl));
					break;
					
				case '!':
					this_thread::sleep_for(chrono::milliseconds(unlm));
					break;
				
				case '?':
					this_thread::sleep_for(chrono::milliseconds(sr));
					break;
				
				case ':':
					this_thread::sleep_for(chrono::milliseconds(inkt));
					break;
			}
		}
		if(dosyaAdi=="texts/1.dat"){
			if(s==1){
				konusan = 0;
				setTextColor(7);
				randomWaitInRange(800, 2000);
			}
			if(s==15){
				SML::PlayEffect("connection");
				setTextColor(4);
				switch (loopRepeat){
					case 1: randomWaitInRange(1200, 11000); break;
					case 2: randomWaitInRange(1200, 10000); break;
					case 3: randomWaitInRange(1200, 8000); break;
					case 4: randomWaitInRange(1200, 6000); break;
					case 5: randomWaitInRange(1200, 4000); break;
					case 6: randomWaitInRange(1200, 2000); break;
					case 7: this_thread::sleep_for(chrono::seconds(1)); break;
					case 8: this_thread::sleep_for(chrono::milliseconds(500)); break;
					default: randomWaitInRange(1200, 11000); break;
				}
			}
			if(tk == 1){
				konusan = 1;
				this_thread::sleep_for(chrono::milliseconds(60));
			}
			if(tk == 2){
				konusan = 0;
				this_thread::sleep_for(chrono::milliseconds(3500));
				setTextColor(7);
				tk ++;
			}
		}
		
		if(dosyaAdi!="texts/1.dat"&&dosyaAdi!="texts/Disconnect.dat"&&dosyaAdi!="texts/Connect.dat"&&dosyaAdi!="texts/Disconnect2.dat"){
			if(s==1){konusan=0; setTextColor(7);}
			if(dd==1){
				SML::PlayEffect("connection");
				setTextColor(15);
				this_thread::sleep_for(chrono::milliseconds(500));
				dd ++;
			}
			if(tk == 1){
				konusan = 2;
				this_thread::sleep_for(chrono::milliseconds(60));
			}
			if(tk == 2){
				konusan = 0;
				setTextColor(7);
				randomWaitInRange(1500, 6000);
				tk++;
			}
			if(dd == 3){
				SML::PlayEffect("connection");
				setTextColor(4);
				randomWaitInRange(400, 5000);
				if (dosyaAdi == "texts/CAAD.dat" && i == 0) {
					// theme1 müziğini 90’dan 0’a 2 birim / 100ms adımla indir: toplam ~4.5s
					SML::FadeOutMusic("theme1", 4.5f);

					zikkiminkoku = 1;

					// 'sound/effect/bach.wav' efektini çal
					SML::PlayFileOnce("breadmusic13.mp3");

					i++;
				}
				if(dosyaAdi=="texts/wrap.dat"&&i==0){
					SML::StopMusic("theme1");
					SML::PlayFileOnce("breadmusic14.mp3");
					i ++;
				}
				dd ++;
			}
			if(tk == 4){
				if(dosyaAdi=="texts/ABBAC.dat"&&porno==0){
					SML::StopMusic("theme1");
					porno ++;
				}
				konusan = 1;
				if((dosyaAdi=="texts/AAA.dat"||dosyaAdi=="texts/AAAlocked.dat")&&i==0){
					SML::StopMusic("theme1");
					SML::PlayFileOnce("breadmusic1.mp3");
					i ++;
				}
				if(dosyaAdi=="texts/AAA.dat"||dosyaAdi=="texts/AAAlocked.dat"){
					randomWaitInRange(40, 500);
				}else{
					if(dosyaAdi=="texts/ABBAC.dat"){
						this_thread::sleep_for(chrono::milliseconds(15));
					}
					this_thread::sleep_for(chrono::milliseconds(60));
				}
			}
			if(tk == 5){
				konusan = 0;
				setTextColor(7);
				if(dosyaAdi=="texts/ABBAC.dat"&&porno==1){
					SML::PlayFileBlocking("breadmusic11.mp3");
					porno ++;
				}
				if (dosyaAdi == "texts/AAA.dat" || dosyaAdi == "texts/AAAlocked.dat") {
					 SML::WaitMusicUntil("breadmusic1", 21.0f);
				}else{
					this_thread::sleep_for(chrono::milliseconds(2250));
				}
				tk ++;
			}
		}
		
		if(dosyaAdi=="texts/Disconnect.dat"){
			if(zikkiminkoku==1) cout <<"\n      "; zikkiminkoku = 0;
			setTextColor(8);
			switch (endl) {
				case 3:
					moveCursorRelative(0, -2);
					s = 0;
					endl++;
					break;
				case 4:
					if(s>=8){
						this_thread::sleep_for(chrono::milliseconds(60));
						konusan = 3;
						if(s==17||s==22){
							this_thread::sleep_for(chrono::milliseconds(80));
						}
						if(s==26||s==29||s==32||s==36){
							this_thread::sleep_for(chrono::milliseconds(130));
						}
						if(s==41){
							this_thread::sleep_for(chrono::milliseconds(3000));
						}
						if(s==13){
							this_thread::sleep_for(chrono::milliseconds(300));
						}
					}
					break;	
			}
		}
		if(dosyaAdi=="texts/Disconnect2.dat"){
			setTextColor(8);
			switch (endl) {
				case 5:
					konusan = 3;
					systemEffect.setPitch(0.4f);
					moveCursorRelative(0, -2);
					endl++;
					break;
				case 6:
					this_thread::sleep_for(chrono::milliseconds(60));
					if(current == ',') this_thread::sleep_for(chrono::milliseconds(200));
					break;
				case 7:
					this_thread::sleep_for(chrono::milliseconds(3000));
					systemEffect.setPitch(1.0f);
			
					break;	
			}
		}
		if(dosyaAdi=="texts/Connect2.dat"){
			setTextColor(8);
			switch (endl) {
				case 5:
					konusan = 3;
					SML::SetEffectPitch("system", 0.4f);
					moveCursorRelative(0, -2);
					endl++;
					break;
				case 6:
					this_thread::sleep_for(chrono::milliseconds(60));
					if(current == ',') this_thread::sleep_for(chrono::milliseconds(200));
					break;
				case 7:
					this_thread::sleep_for(chrono::milliseconds(3000));
					SML::SetEffectPitch("system", 1.0f);
					break;	
			}
		}
		if(dosyaAdi=="texts/Connect.dat"){
			setTextColor(8);
			switch (endl) {
				case 3:
					moveCursorRelative(0, -2);
					s = 0;
					endl++;
					break;
				case 4:
					if(s>=8){
						this_thread::sleep_for(chrono::milliseconds(65));
						konusan = 3;
						if(s==26||s==29||s==32){
							this_thread::sleep_for(chrono::milliseconds(15));
						}
						if(s>=35){
							this_thread::sleep_for(chrono::milliseconds(100));
						}
						
					}
					break;	
			}
		}
		if(dosyaAdi=="texts/Unlock.dat"||dosyaAdi=="texts/OffensiveUnlock.dat"){
			
			if(aptalonay==0) {
				//moveCursor(6,10);
				aptalonay ++;
			}
			
			setTextColor(8);
			switch (endl) {
				case 4:
					moveCursorRelative(0, -2);
					s = 0;
					endl++;
					break;
				case 5:
					if(s>=8){
						this_thread::sleep_for(chrono::milliseconds(70));
						konusan = 3;
						if(dosyaAdi=="texts/OffensiveUnlock.dat"){
							if(s>=43){
								this_thread::sleep_for(chrono::milliseconds(100));
							}
						}
						else{
							if(s>=36){
								this_thread::sleep_for(chrono::milliseconds(100));
							}
						}
						
						
					}
					break;	
			}
		}
		
		s ++;
		z ++;
		
		current = next;
	}
	
	cout << current;
	
	SML::UnloadEffect("bread");
	SML::UnloadEffect("you");
	SML::UnloadEffect("system");
	SML::UnloadEffect("connection");
	
	setTextColor(15);
	
	if(dosyaAdi=="texts/ACDDDDD.dat") moveCursorRelative(0, -1);
	cursorPosition = getCursorPosition();
	
	dosya.close();
	remove("texts/temp_decrypted.dat");
}
void darkthemes() {
    // 1) theme2 müziğini hazırla ve tam sese getir
    SML::SetMusicVolume("breadmusic9", 100.f);

    // 2) darktheme.mp3 dosyasını çal (sound/music/darktheme.mp3)
    SML::PlayFileOnce("breadmusic10.mp3", /*loop=*/false, /*volume=*/100.f);

    // 3) volume’u 100 → 25 arası indir
    {
        float vol = 100.f;
        while (vol > 18.f) {
            vol -= 1.f;
            SML::SetMusicVolume("breadmusic9", vol);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    // 4) volume’u 25 → 100 arası tekrar yükselt
    {
        float vol = 20.f;
		float vol2 = 100.f;
        while (vol < 100.f&&vol2 > 10) {
            vol += 1.f;
			vol2 -= 1.f;
            SML::SetMusicVolume("breadmusic9", vol);
			SML::SetMusicVolume("breadmusic10", vol2);
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
    }
}
void pitchTheme1() {
    // 1) breadmusic9.mp3 yerine pitchtheme1.mp3 dosyasını çal, tam sesle başla
    if (SML::PlayFileOnce("breadmusic8.mp3", /*loop=*/false, /*vol=*/100.f)) {
        // 2) 100 → 0 arasında, her 0.5 adımda 120ms bekleyerek fade-out
        float volume = 100.f;
        while (volume > 0.f) {
            volume -= 0.5f;
            if (volume < 0.f) volume = 0.f;
            SML::SetMusicVolume("theme1", volume);
            std::this_thread::sleep_for(std::chrono::milliseconds(120));
        }
    }
	SML::UnloadMusic("theme1");
}
void pitchTheme2() {
    // 1) Aynı mantıkla pitchtheme2.mp3'ü çal
    if (SML::PlayFileOnce("breadmusic9.mp3", /*loop=*/false, /*vol=*/100.f)) {
        // 2) 100 → 0 arasında, her 0.5 adımda 170ms bekleyerek fade-out
        float volume = 100.f;
        while (volume > 0.f) {
            volume -= 0.5f;
            if (volume < 0.f) volume = 0.f;
            SML::SetMusicVolume("breadmusic8", volume);
            std::this_thread::sleep_for(std::chrono::milliseconds(170));
        }
    }
}
void keyEffect() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0.0, 1.0);

    double r = dis(gen);
    if (r < 1.0 / 3.0) {
        SML::PlayEffect("key1");
    } else if (r < 2.0 / 3.0) {
        SML::PlayEffect("key2");
    } else {
        SML::PlayEffect("key3");
    }
}
void spaceEffect() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0.0, 1.0);

    double r = dis(gen);
    if (r < 1.0 / 3.0) {
        SML::PlayEffect("space1");
    } else if (r < 2.0 / 3.0) {
        SML::PlayEffect("space2");
    } else {
        SML::PlayEffect("space3");
    }
}
void backspaceEffect() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0.0, 1.0);

    double r = dis(gen);
    if (r < 1.0 / 3.0) {
        SML::PlayEffect("backspace1");
    } else if (r < 2.0 / 3.0) {
        SML::PlayEffect("backspace2");
    } else {
        SML::PlayEffect("backspace3");
    }
}
void startMouseHook() {
	disableQuickEditAndEnableMouseInput();
    g_hMouseHook = SetWindowsHookEx(
        WH_MOUSE_LL,
        LowLevelMouseProc,
        GetModuleHandle(nullptr),
        0
    );
    if (!g_hMouseHook) {
        std::cerr << "Hook kurulamadı! (Yönetici haklarıyla deneyin)" << std::endl;
        return;
    }

	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

    UnhookWindowsHookEx(g_hMouseHook);
}
void waitForInput(atomic<bool>& running) {
    this_thread::sleep_for(chrono::milliseconds(180));
	int x = position.X;
	pressed = false;
	setTextColor(15);
    while (running.load()) {
  
		int y = position.Y;
		
        while (!pressed && running.load()) {

			moveCursor(x, y);
			cout << "->";

            for (int past = 0; past <= 60; past++) {
                if(pressed) goto etiket;
                this_thread::sleep_for(chrono::milliseconds(3));
            }
			
			
			
			moveCursor(x, y);
			cout << "  ";	
			
            for (int past = 0; past <= 60; past++) {
                if (pressed) goto etiket;
                this_thread::sleep_for(chrono::milliseconds(3));
            }
        }
		etiket:
		
        y = position.Y;
		
		pressed = false;
				
        for (int past = 0; past <= 300 && running.load(); past++) {
			if(!running.load()) break;
            if(pressed) past = 0;
			pressed = false;
            this_thread::sleep_for(chrono::milliseconds(3));
        }
	
        x-2;
    }
}
void displayMenu(int& s) {
    clearInputBuffer();
	isEventMouse = false;
	
    SML::PlayEffectFile("effect4.wav"); //fall
	
	char Info;
    atomic<bool> running{ true };
	
	pressed = false; 
	s = 1;
	
    thread waitThread(waitForInput, ref(running));
	
    moveCursor(cursorPosition.X+8, cursorPosition.Y-4);

    position = getCursorPosition();

    startPosition = getCursorPosition();
	
    renklendir(position.X + 5, position.Y, 80, 15);

    int y = position.Y;
    this_thread::sleep_for(chrono::milliseconds(600));

    DWORD lastPressTime = GetTickCount();
	
	setTextColor(15);
	
	SML::LoadEffect("click", "sound/effect/effect1.wav");
	SML::LoadEffect("click2", "sound/effect/effect16.wav");
	
	bool dawn = true;
	
    while (true) {
     
        position = getCursorPosition();
        
		if(isEventMouse.load()){
			pressed = true;
			DWORD now = GetTickCount();
			if (isLeftButtonDown.load()) {
                running.store(false); // thread'e dur sinyali
                if (waitThread.joinable()) waitThread.join(); // thread'i düzgün sonlandır
				content = readConsoleRegion(position.X+4, position.Y, 80, 1);
				
				ofstream dynamicAnswerFile(dosyaDynamicAnswer, ios::trunc);
				if (!dynamicAnswerFile) {
					cerr << "texts/dynamicAnswer.dat dosyası açılamadı!\n";
					return;
				}
				dynamicAnswerFile << endl << "         You: " << content;
				dynamicAnswerFile.close();
				
                switch (s) {
                    case 1: Info = 'A'; break;
                    case 2: Info = 'B'; break;
                    case 3: Info = 'C'; break;
                    case 4: Info = 'D'; break;
                    default: Info = '?'; break;
                }

                const char* appDataPath = getenv("APPDATA");
                if (!appDataPath) {
                    cerr << "APPDATA yolu alınamadı!" << endl;
                    return;
                }

                string dosyaYolu = string(appDataPath) + "\\pathInfo.dat";
                ofstream dosya(dosyaYolu, ios::app);
                if (dosya.is_open()) {
                    dosya << Info << endl;
                    dosya.close();
                } else {
                    cerr << "Dosya açılamadı!" << endl;
                }

                clearArea(startPosition.X - 2, startPosition.Y - 1, 120, 6);
                moveCursor(0, cursorPosition.Y - 1);
				
				cursorLimit = 3;
				
				isEventMouse.store(false);
				
				
                return;
			} else {
				if (now - lastPressTime >= 150) {
					if (dawn) {
							s++;
							moveCursor(position.X - 2, position.Y);
							cout << "  ";
							renklendir(position.X + 4, position.Y, 91, 7);
							position.Y++;
							moveCursor(position.X - 2, position.Y);
							cout << "->";
							renklendir(position.X + 4, position.Y, 91, 15);
							if(fileNameControl=="texts/ACDDDDD.dat"&&s==4) renklendir(position.X + 4, position.Y+1, 91, 15);
							SML::PlayEffect("click2");
							if(s == cursorLimit+1) dawn = false;
					} else {
							s--;
							moveCursor(position.X - 2, position.Y);
							cout << "  ";
							renklendir(position.X + 4, position.Y, 91, 7);
							if(fileNameControl=="texts/ACDDDDD.dat"&&s!=4) renklendir(position.X + 4, position.Y+1, 91, 7);
							position.Y--;
							moveCursor(position.X - 2, position.Y);
							cout << "->";
							renklendir(position.X + 4, position.Y, 91, 15);
							SML::PlayEffect("click");
							if(s == 1) dawn = true;
					}
					lastPressTime = now;
				}
			}
			isEventMouse.store(false);
			isLeftButtonDown.store(false);
		}

        if (_kbhit()) {
            int ch = _getch();

            if (ch == 224) {
				pressed = true;
                int key = _getch();
                DWORD now = GetTickCount();

                if (now - lastPressTime >= 150) {
                    if (key == 72 && position.Y > y) {
						s--;
						moveCursor(position.X - 2, position.Y);
						cout << "  ";
                        renklendir(position.X + 4, position.Y, 91, 7);
						if(fileNameControl=="texts/ACDDDDD.dat"&&s!=4) renklendir(position.X + 4, position.Y+1, 91, 7);
                        position.Y--;
                        moveCursor(position.X - 2, position.Y);
                        cout << "->";
                        renklendir(position.X + 4, position.Y, 91, 15);
                        SML::PlayEffect("click");
                    }
                    else if (key == 80 && position.Y < y + cursorLimit) {
						s++;
                        moveCursor(position.X - 2, position.Y);
                        cout << "  ";
                        renklendir(position.X + 4, position.Y, 91, 7);
                        position.Y++;
                        moveCursor(position.X - 2, position.Y);
                        cout << "->";
                        renklendir(position.X + 4, position.Y, 91, 15);
						if(fileNameControl=="texts/ACDDDDD.dat"&&s==4) renklendir(position.X + 4, position.Y+1, 91, 15);
                        SML::PlayEffect("click2");
                    }
                    lastPressTime = now;
                }
            } else if (ch == 13) {
                while (_kbhit()) _getch(); // girişi temizle
				pressed = true;
				
                running.store(false); // thread'e dur sinyali
                if (waitThread.joinable()) waitThread.join(); // thread'i düzgün sonlandır
				
				content = readConsoleRegion(position.X+4, position.Y, 80, 1);
				
				ofstream dynamicAnswerFile(dosyaDynamicAnswer, ios::trunc);
				if (!dynamicAnswerFile) {
					cerr << "texts/dynamicAnswer.dat dosyası açılamadı!\n";
					return;
				}
				dynamicAnswerFile << endl << "         You: " << content;
				dynamicAnswerFile.close();
				
                switch (s) {
                    case 1: Info = 'A'; break;
                    case 2: Info = 'B'; break;
                    case 3: Info = 'C'; break;
                    case 4: Info = 'D'; break;
                    default: Info = '?'; break;
                }

                const char* appDataPath = getenv("APPDATA");
                if (!appDataPath) {
                    cerr << "APPDATA yolu alınamadı!" << endl;
                    return;
                }

                string dosyaYolu = string(appDataPath) + "\\pathInfo.dat";
                ofstream dosya(dosyaYolu, ios::app);
                if (dosya.is_open()) {
                    dosya << Info << endl;
                    dosya.close();
                } else {
                    cerr << "Dosya açılamadı!" << endl;
                }

                clearArea(startPosition.X - 2, startPosition.Y - 1, 120, 6);
                moveCursor(0, cursorPosition.Y - 1);
				
				cursorLimit = 3;
				
                return;
            } else if (ch == 27) {
                s = 0;
				pressed = true;
				
                returnToMenu = true;
                running.store(false); // thread'e dur sinyali
                if (waitThread.joinable()) waitThread.join(); // thread'i düzgün sonlandır
				
                system("cls");
                setTextColor(7);
                
				SML::StopMusic("theme1");
				SML::StopMusic("theme2");

                centerText("Disconnecting . . .");
                return;
            }
        }
        this_thread::sleep_for(chrono::milliseconds(3));
    }
}
void makeInfo() {
    // C++11 ve sonrasında önerilen chrono kütüphanesi kullanılarak şu anki zaman alınır
    auto now = chrono::system_clock::now();

    // Zamanı yerel saate dönüştür
    time_t timeNow = chrono::system_clock::to_time_t(now);

    // Güncel saati yazdır
    // APPDATA yolunu al
    const char* appDataPath = getenv("APPDATA");
    if (!appDataPath) {
        cerr << "APPDATA yolu alınamadı!" << endl;
        return;
    }

    // pathInfo.dat dosyasının tam yolu
    string dosyaYolu = string(appDataPath) + "\\pathInfo.dat";

    // Dosyayı aç ve yaz
    ofstream dosya(dosyaYolu, ios::app);
    if (!dosya.is_open()) {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }

    // Zamanı dosyaya yaz
	if(breadsEncryptedPort) dosya << "Reached the breadsEncryptedPort - - - ";
    dosya << "NEW START " << "(" << put_time(localtime(&timeNow), "%H:%M:%S") << ") (" << progress << ")" << endl;

    // Dosyayı kapat
    dosya.close();
}
void simulateAltEnter() {
    HWND console = GetConsoleWindow();
    if (console) {
        SendMessage(console, WM_SYSKEYDOWN, VK_RETURN, 0x20000000); // ALT + ENTER'i simüle eder
    }
}
void start(const string& exeName) {
    // Programın çalıştığı dizini al
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    string currentDir = buffer;
    currentDir = currentDir.substr(0, currentDir.find_last_of("\\/")); // Dizini al

    // Belirtilen exe dosyasının tam yolunu oluştur
    string exePath = currentDir + "\\" + exeName;

    // Exe'yi çalıştır
    STARTUPINFO si = {0};
    PROCESS_INFORMATION pi = {0};

    if (CreateProcess(
        exePath.c_str(),    // Yürütülecek program
        NULL,               // Komut satırı parametreleri
        NULL,               // Güvenlik özellikleri
        NULL,               // Process handle'ı
        FALSE,              // Çocuk süreçten inheritance yapılacak mı?
        CREATE_NO_WINDOW,   // Pencere açmadan çalıştır
        NULL,               // Çevresel değişkenler
        currentDir.c_str(), // Çalıştırılacak dizin (oyunun dizini)
        &si,                // Başlatma bilgileri
        &pi                 // Süreç bilgileri
    )) {
        // Başarıyla başlatıldıysa
        //cout << exeName << " basariyla baslatildi!" << endl;
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        // Başlatılamadıysa hata mesajı
        cerr << exeName << " baslatilamadi!" << endl;
    }

    // Kısa bir bekleme
    this_thread::sleep_for(chrono::milliseconds(50));
}
void stop(const string& exeName) {
    // Process snapshot'ı alıyoruz
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    // Sistem üzerindeki süreçlerin anlık görüntüsünü alıyoruz
    HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE) {
        cerr << "Process snapshot alinamadi!" << endl;
        return;
    }

    // İlk işlemi alıyoruz
    if (Process32First(hProcessSnap, &pe32)) {
        do {
            // İşlem adıyla karşılaştırma yapıyoruz
            if (exeName == pe32.szExeFile) {
                // Process ID (PID) bulunduktan sonra işlemi sonlandırıyoruz
                HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe32.th32ProcessID);
                if (hProcess != NULL) {
                    TerminateProcess(hProcess, 0);  // İşlemi sonlandırıyoruz
                    //cout << exeName << " basariyla kapatildi." << endl;
                    CloseHandle(hProcess);
                    break;
                }
            }
        } while (Process32Next(hProcessSnap, &pe32));  // Diğer süreçleri kontrol ediyoruz
    }
    CloseHandle(hProcessSnap);
	this_thread::sleep_for(chrono::milliseconds(500));
}
void pauseTheSystem() {
	setTextColor(7);
    cout << "Press any key to continue . . .\n";
	SML::PlayEffectFile("effect17.wav");
	isEventMouse.store(false);
	clearInputBuffer();
	
    while (true) {
        if (_kbhit()) {
            _getch();  // herhangi bir tuşa basıldı
            break;
        }
		if(isEventMouse.load()) {
			isEventMouse.store(false);
			break;
		}
        Sleep(50);  // CPU'yu yorma
    }
}
void theMysteryOfJohnDensmore(){
	HWND hwnd = GetConsoleWindow();
	simulateAltEnter();
	system("cls");
	hideCursor();
	setConsoleFont(L"SimSun-ExtB", 17);
	setConsoleSize(120, 30);
	printImageAsASCII("John_Densmore_1971.png");
	SetWindowText(hwnd, "                                                                                                                       theMysteryOfJohnDensmore");
	thread t(hookThread);
	t.detach();
	SML::StopAll();
	SML::PlayFileOnce("breadmusic2.mp3");
	stop("hook.exe");
	SystemParametersInfo(SPI_SETCURSORS, 0, 0, 0);
	SML::WaitMusic("breadmusic2");
}
void writeProgress() {
    // APPDATA yolunu al
    char* appdataPath = std::getenv("APPDATA");
    if (!appdataPath) return; // APPDATA yoksa çık

    std::string progressPath = std::string(appdataPath) + "\\progress.dat";

    std::ifstream file(progressPath);
    if (!file.is_open()) return; // Dosya açılamadıysa çık

    int lineCount = 0;
    std::string line;
    while (std::getline(file, line)) {
        lineCount++;
    }

    file.close();

    // ayar.dat normal dizindeyse
    std::ifstream inFile("ayar.dat");
    std::vector<std::string> lines;

    while (std::getline(inFile, line)) {
        lines.push_back(line);
    }

    inFile.close();

    if (lines.size() >= 3) {
        lines[2] = std::to_string(lineCount);
    } else {
        while (lines.size() < 2) {
            lines.push_back("");
        }
        lines.push_back(std::to_string(lineCount));
    }

    std::ofstream outFile("ayar.dat");
    for (const auto& l : lines) {
        outFile << l << std::endl;
    }
}
void checkAyar() {
    ifstream file("ayar.dat");

    if (!file.is_open()) {
        cerr << "ayar.dat dosyası bulunamadı! Siktirme! ----Recep Sihhiyecioglu" << endl;
        Sleep(4000);
        exit(0);
    }

    string line1, line2, line3;
    getline(file, line1);
    getline(file, line2);
	getline(file, line3);
    file.close();

    int deger1, deger2, deger3;

    deger1 = stoi(line1);
    deger2 = stoi(line2);
	deger3 = stoi(line3);

    switch (deger1) {
        case 2:
            AAADlock = false;
            ACDDDloop = true;
            break;
        case 1:
            portDeleted = true;
			ACDDDloop = true;
            break;
        case 0:
            AAADlock = true;
            portDeleted = false;
            break;
        default:
            Sleep(1000);
            system("cls");
            centerText(
              "Oyun dosyalarini kurcalama, ne yaptiysan eski haline geri getir: "
              "Sikerim senin belani! ---Recep Sihhiyecioglu"
            );
            Sleep(5000);
            exit(0);
    }

    switch (deger2) {
        case 0:
            offensiveAnswersLocked = false;
            break;
        case 1:
            offensiveAnswersLocked = true;
            break;
        default:
            Sleep(1000);
            system("cls");
            centerText(
              "Oyun dosyalarini kurcalama, ne yaptiysan eski haline geri getir: "
              "Sikerim senin belani! ---Recep Sihhiyecioglu"
            );
            Sleep(5000);
            exit(0);
    }
	
	progress = deger3;
	
	if(progress==201) gameFinished = true;
}
void changeAyar(int Deger, int satirSayisi) {
    string dosyaYolu = "ayar.dat";
    vector<string> satirlar;

    ifstream dosyaOku(dosyaYolu);
    string line;
    while (getline(dosyaOku, line)) {
        satirlar.push_back(line);
    }
    dosyaOku.close();

    if (satirSayisi >= 1 && satirSayisi <= satirlar.size()) {
        satirlar[satirSayisi - 1] = to_string(Deger);
    } else if (satirSayisi == satirlar.size() + 1) {
        satirlar.push_back(to_string(Deger));
    } else {
        cerr << "Geçersiz satır sayısı!" << endl;
        return;
    }

    ofstream dosyaYaz(dosyaYolu, ios::trunc);
    for (const auto& s : satirlar) {
        dosyaYaz << s << '\n';
    }
    dosyaYaz.close();
}
void lockTheAnswer(bool lock){
	moveCursorRelative(+8, -1);
	COORD position = getCursorPosition();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int row = position.Y;         // 5. satır (çünkü 0'dan başlıyor)
    const int colStart = position.X;    // 5. sütun
    const int maxWidth = 113;  // maksimum satır uzunluğu
    CHAR buffer[maxWidth];
    DWORD charsRead;
    COORD startCoord = {0, static_cast<SHORT>(row)};

    // Satırın tamamını oku
    if (ReadConsoleOutputCharacterA(hConsole, buffer, maxWidth, startCoord, &charsRead)) {
        // 5. sütundan başlayarak 'f' karakterini ara
        for (int i = colStart + 8; i < (int)charsRead; ++i) {
            if (buffer[i] == '"') {
                // f'nin hemen sağına yaz
                COORD msgPos = { (SHORT)(i + 1), (SHORT)row };
                SetConsoleCursorPosition(hConsole, msgPos);
				if(offensiveAnswersLocked||lock){
					cout << " [LOCKED]";
				}else{
					cout << " [UNLOCKED]";
				}
                break;
            }
        }
    } else {
        cout << "Satır okunamadı!";
    }
	if(offensiveAnswersLocked||lock){
		renklendir(position.X, position.Y, 80, 8);
		cursorLimit = 2;
	}else{
		renklendir(position.X, position.Y, 80, 7);
	}
}
void setSounds() {
	UnknownPort.setLoop(true);
	theme1.setLoop(true);
	
	enter.setVolume(60);
	backspace1.setVolume(60);
	backspace2.setVolume(60);
	backspace3.setVolume(60);
	key1.setVolume(60);
	key2.setVolume(60);
	key3.setVolume(60);
	space1.setVolume(60);
	space2.setVolume(60);
	space3.setVolume(60);
	
	welcomeEffect.setVolume(60);
	youEffect.setVolume(60);
	breadEffect.setVolume(60);
	theme1.setVolume(90);
}
void setCustomConsoleColorPalette() {
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        std::cerr << "GetStdHandle failed\n";
        return;
    }

    // 1) Mevcut palette'i oku
    CONSOLE_SCREEN_BUFFER_INFOEX csbiex = {};
    csbiex.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    if (!GetConsoleScreenBufferInfoEx(hConsole, &csbiex)) {
        std::cerr << "GetConsoleScreenBufferInfoEx failed\n";
        return;
    }
    csbiex.ColorTable[1] = RGB(40, 15, 15);  // Çok koyu mor2on

    // Daha ekstrem: renk 2'yi tam siyah yerine hemen hemen siyah ama kırmızı biraz olsun ekliyoruz
    csbiex.ColorTable[2] = RGB(15, 15, 40);
	
	csbiex.ColorTable[3] = RGB(15, 40, 15);
	
	csbiex.ColorTable[4] = RGB(230, 230, 230);
	
	csbiex.ColorTable[6] = RGB(150, 150, 150);
	
     // 3) Yeni palette'i yükle
    if (!SetConsoleScreenBufferInfoEx(hConsole, &csbiex)) {
        std::cerr << "SetConsoleScreenBufferInfoEx failed\n";
        return;
    }

    // 4) İstediğin indeksi text rengi olarak kullan
    //    (arkaplan için index<<4, ikisini birden istiyorsan index|(index<<4))
    SetConsoleTextAttribute(hConsole, 4);
	SetConsoleTextAttribute(hConsole, 6);
}
void setConsoleBackgroundColor(WORD bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD topLeft = {0, 0};
    DWORD charsWritten;

    // Yeni renk: arkaplan = bgColor, ön plan = mevcut ön planı koru
    WORD currentAttrs = csbi.wAttributes;
    WORD newAttrs = (bgColor << 4) | (currentAttrs & 0x0F);

    // Tüm ekranı boşluk karakteriyle temizle ve yeni renk uygula
    FillConsoleOutputCharacter(hConsole, ' ', consoleSize, topLeft, &charsWritten);
    FillConsoleOutputAttribute(hConsole, newAttrs, consoleSize, topLeft, &charsWritten);

    // Renkleri set et
    SetConsoleTextAttribute(hConsole, newAttrs);

    // İmleci en üste taşı
    SetConsoleCursorPosition(hConsole, topLeft);
}
void enableDPIAwareness() {
    SetProcessDPIAware(); // DPI'nın doğru ölçülmesi için
}
int getCurrentDPI() {
    HDC hdc = GetDC(NULL);
    int dpiY = GetDeviceCaps(hdc, LOGPIXELSY);
    ReleaseDC(NULL, hdc);
    return dpiY;
}
void getScreenResolution(int& width, int& height) {
    width = GetSystemMetrics(SM_CXSCREEN);
    height = GetSystemMetrics(SM_CYSCREEN);
}

HCURSOR createInvisibleCursor() {
    char ANDmask[32] = { 0 };
    char XORmask[32] = { 0 };
    return CreateCursor(nullptr, 0, 0, 8, 8, ANDmask, XORmask);
}
static bool one = true;
void lockAndHideCursor() {
    static HCURSOR hInvisible = createInvisibleCursor();
    SetSystemCursor(hInvisible, OCR_NORMAL);

    int centerX = GetSystemMetrics(SM_CXSCREEN) / 2;
    int centerY = GetSystemMetrics(SM_CYSCREEN) / 2;

    while (true) {
        SetCursorPos(centerX, centerY);
		this_thread::sleep_for(chrono::milliseconds(2));
    }
}
char getValidInput() {  
    while (true) {
        // Fare olayını önce kontrol et
        if (isEventMouse.load()) {
			isEventMouse.store(false);
			if(isLeftButtonDown.load()){
				char result = 13;
				return result;
			} else {
				char result = one ? '1' : '0';
				one = !one;
				return result;
			}
        }

        // Klavyede basılmış tuş var mı diye bak
        if (_kbhit()) {
            int c = _getch();               // int olarak al
            if (c == 0 || c == 224) {       // özel tuş koduysa
                _getch();                   // sonraki ek kodu yut
                continue;
            }
            // Yazdırılabilir ASCII, Enter veya Backspace
            if ((c >= 32 && c <= 126) || c == 13 || c == 8) {
                return c;
            }
        }

        // CPU’yu rahatlatmak için kısa uyku
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
void playSilentLoop() {
    static sf::Music silentMusic;
    if (!silentMusic.openFromFile("sound/effect/silence.wav")) {
        cerr << "FUCK";
        return;
    }   
    silentMusic.setLoop(true);     // sonsuz döngü
    silentMusic.play();
}

int main() {
	playSilentLoop();
	start("hook.exe");

	setCustomConsoleColorPalette();
	
	simulateAltEnter();
	
	HWND hwnd = GetConsoleWindow();
	setConsoleSize(113, 30);
	
	loopRepeat = 0;
	
	start:
	
	SetConsoleOutputCP(CP_UTF8);
	setConsoleToNonQuickEditMode();
	
	hideCursor();
	
	enableDPIAwareness();
	
	//wcout << L"Font DPI " << getCurrentDPI;
	
	setConsoleFont(L"Simsun-ExtB", 27);
	
	moveCursor(0,0);
	
    SetWindowText(hwnd, "Bread");
	
	thread breadThread(BreadSystem);
	breadThread.detach();
	
	thread breadThread2(startMouseHook);
	breadThread2.detach();
	
	checkAyar();
	writeProgress();
	
	if(gameFinished) setConsoleBackgroundColor(3);
	if(portDeleted) setConsoleBackgroundColor(2);
	if(!AAADlock) setConsoleBackgroundColor(1);
	
	setTextColor(6);
	
	centerText("Loading. . .");
	
	this_thread::sleep_for(chrono::seconds(3));
	
	float disconnectionPitch = 1.0f;
	float mainThemePitch = 1.0f;
	float theme1Pitch = 1.0f;
	
	SML::PlayFileOnce("breadmusic3.mp3", false);
	
	while(true) {
		if(gameFinished) setConsoleBackgroundColor(3);
		if(portDeleted) setConsoleBackgroundColor(2);
		if(!AAADlock) setConsoleBackgroundColor(1);
		bool permissonD = true;
		returnToMenu = false;
		checkAyar();
		writeProgress();
		
		loopRepeat ++;
		
		if(loopRepeat>1&&!gameFinished){
			SML::StopAll();
			SML::UnloadAll();
			if(loopRepeat>2) disconnectionPitch -= 0.05f;
			if(loopRepeat>2) mainThemePitch -= 0.05f;
			if(loopRepeat>2) theme1Pitch -= 0.05f; 
			SML::PlayFileOnce("breadmusic4.mp3", false, 100.f, mainThemePitch);
		}
			
		char input;
		string text;
		string text2;
		string inputString;
		breadsEncryptedPort = false;
		system("cls");
		setTextColor(15);
		moveCursor(0 ,0);
		centerText("Bread: A Universal Revolution ", false);
		setTextColor(7);
		centerText("Enter '1' to chat with Bread        or        Enter '0' to close");
		cout << "\n\n";
		centerText("Enter a valid entry and press 'Enter'. . .", false);
		cout << "\n\n";
		centerText(">>> <<<", false);
		
		moveCursor(105, 29);
		
		//progress = 200;
		
		cout << progress << "/201";
		
		showCursor();
		setTextColor(15);
		COORD position = { 56, 19 };
		isMainMenu = true;
		
		clearInputBuffer();
		isEventMouse.store(false);
			
		SML::LoadEffect("key", "sound/effect/keyboard/key2.wav");
		SML::LoadEffect("space", "sound/effect/keyboard/space3.wav");
		SML::LoadEffect("backspace", "sound/effect/keyboard/backspace1.wav");
		SML::LoadEffect("enter", "sound/effect/keyboard/enter.wav");
		
		one = true;
		
		while(isMainMenu){
			moveCursor(position.X, position.Y);
			input = getValidInput();
			moveCursor(position.X, position.Y);
			
			if(input == 8){
				SML::PlayEffect("backspace", false, 65.f);
			}
			else if(input == 13){
				SML::PlayEffect("enter", false, 55.f);
			}
			else if(input == ' '){
				SML::PlayEffect("space", false, 65.f);
			} else {
				SML::PlayEffect("key", false, 65.f);
			}
			
			if(input != 8 && input != 13){
				text += input;
				cout<<input<<flush;
			}
			
			if(input==8&&!text.empty()){
				moveCursor(position.X, position.Y);
				text.pop_back();
				cout << " " << flush;
				continue;
			}
			
			if(input==13&&text.length() >= 1){
				input = text[text.length() - 1];
				inputString += input;
				switch (input) {
					case '0':
					{
						SML::StopMusic("breadmusic3");
						SML::StopMusic("breadmusic4");
						HWND hCon = GetConsoleWindow();
						if (hCon) {
							ShowWindow(hCon, SW_HIDE);
						}
						FreeConsole();
						this_thread::sleep_for(chrono::milliseconds(1000));
						exit(0);
					}
					case '1':
					{
						isMainMenu = false;
						break;
					}
					default:
					{
						hideCursor();
						moveCursor(position.X, position.Y);
						cout << " " <<  flush;
						moveCursor(position.X-13, position.Y-2);
						cout << "valid" <<  flush;
						showCursor();
						break;
					}
				}	
			}
			
			if (inputString.length() >= 2) {
				string lastTwo = inputString.substr(inputString.length() - 2);

				if (lastTwo == "67") {
					theMysteryOfJohnDensmore();
				}
			}
			
			if (inputString.length() >= 14) {
				string lastFourteen = inputString.substr(inputString.length() - 14);

				if (lastFourteen == "O6YDXQ6PFZAO79") {
					breadsEncryptedPort = true;
				}
			}
		}
		
		const char* appDataPath = getenv("APPDATA");

		string dosyaYolu = string(appDataPath) + "\\pathInfo.dat";
		ofstream dosya(dosyaYolu, ios::app);
					
		if (dosya.is_open()) { 
			dosya << "\n---MAIN MENU TYPE---\n" << text <<"---MAIN MENU TYPE---\n\n";
			dosya.close();
		} else {
			cerr << "Dosya açılamadı!" << endl;
		}
		
		makeInfo();
			
		hideCursor();
		
		SML::UnloadEffect("key");
		SML::UnloadEffect("space");
		SML::UnloadEffect("backspace");
		SML::UnloadEffectWhenFinished("enter");
		
		SML::StopAndUnloadFile("breadmusic4");
		SML::StopAndUnloadFile("breadmusic3");
		
		if(!breadsEncryptedPort) SML::LoadMusic("theme1", "sound/music/breadmusic5.mp3");
		
		if(breadsEncryptedPort){
			SML::PlayFile("breadmusic6.mp3", true);
			this_thread::sleep_for(chrono::seconds(6));
		}
		
		system("cls");
		
		setTextColor(7);
		
		randomWaitInRange(500, 2000);
		centerText("Connecting . . .");
		randomWaitInRange(1000, 5000);
		if((!portDeleted&&breadsEncryptedPort)||!breadsEncryptedPort) SML::PlayFileOnce("effect5.wav");
		if(breadsEncryptedPort) randomWaitInRange(3000, 10000);
		
		if(breadsEncryptedPort) centerText("Unknown Port . . .");
		
		if(breadsEncryptedPort) randomWaitInRange(1000, 3500);
		if(portDeleted&&breadsEncryptedPort) randomWaitInRange(4000, 10500);
		
		if(breadsEncryptedPort&&portDeleted) centerText("Error: Port 'O6YDXQ6PFZAO79' has been terminated.");
		
		if(portDeleted&&breadsEncryptedPort) randomWaitInRange(2000, 6500); system("cls");
		
		if(portDeleted&&breadsEncryptedPort) goto start;
		
		if(breadsEncryptedPort&&!portDeleted) centerText("Reconnecting . . .");
		
		
		randomWaitInRange(1000, 5000);
		if(breadsEncryptedPort) randomWaitInRange(2000, 7000);
		
		system("cls");
		
		randomWaitInRange(800, 2000);
		
		//////////////////////////////////////////////CHAT STARTS/////////////////////////////////////////////////////
		
		//setConsoleSize(113, 30);
		
		if(!breadsEncryptedPort) bilmemne(0, 0, 0, 0, 0, 0, dosyaConnect);

		this_thread::sleep_for(chrono::milliseconds(500));		
		
		if(!breadsEncryptedPort&&!gameFinished) SML::PlayMusic("theme1", true, 100.f, theme1Pitch);
		
		SML::LoadEffect("Connection", "sound/effect/effect3.wav");

		if(breadsEncryptedPort){
			SML::LoadEffect("key1", "sound/effect/keyboard/key1.wav");
			SML::LoadEffect("key2", "sound/effect/keyboard/key2.wav");
			SML::LoadEffect("key3", "sound/effect/keyboard/key3.wav");
			SML::LoadEffect("space1", "sound/effect/keyboard/space1.wav");
			SML::LoadEffect("space2", "sound/effect/keyboard/space2.wav");
			SML::LoadEffect("space3", "sound/effect/keyboard/space3.wav");
			SML::LoadEffect("backspace1", "sound/effect/keyboard/backspace1.wav");
			SML::LoadEffect("backspace2", "sound/effect/keyboard/backspace2.wav");
			SML::LoadEffect("backspace3", "sound/effect/keyboard/backspace3.wav");
			SML::LoadEffect("enter", "sound/effect/keyboard/enter.wav");
			
			moveCursor(0, 0);
			bilmemne(300, 600, 0, 500, 0, 300, dosyaConnect2);
			setTextColor(7);
			randomWaitInRange(2000, 10000);
			cout << "The Programmer: ";
			SML::PlayEffect("Connection");
			setTextColor(15);
			randomWaitInRange(1200, 11000);
			cout << "\" \"";
			moveCursorRelative(-2, 0);
			
			COORD startPosition = getCursorPosition();
			COORD currentPosition;
			int x = startPosition.X;
			int y = startPosition.Y;
			vector<TypedChar> buffer = loadFromFile("texts/kayit.dat");
			int lenght = 0;
			int totalLenght = 0;

			for (const auto& entry : buffer) {
				currentPosition = getCursorPosition ();
				this_thread::sleep_for(chrono::milliseconds(entry.delayMs));

				if (entry.isBackspace) {
					cout <<"  ";
					moveCursorRelative(-2, 0);
					cout << "\b \b";
					backspaceEffect();
					lenght--;
				} else {
					if(entry.ch==' '){
						spaceEffect();
					}else{
						if(entry.ch!='.'){
							keyEffect();
						} else {
							SML::PlayEffect("key1");
						}
						
					}
					if(entry.ch != ' ' || lenght != 0){
						if(entry.ch!='#'){
							cout << entry.ch;
						} else {
							moveCursorRelative(+2, 0);
							cout <<"\b\b\"";
							SML::PlayEffect("enter");
							break;
						}
						lenght++;
					}
					if (lenght==82){
						cout << " ";
						moveCursorRelative(-83, +1);
						lenght = 0;
					}
				}
				cout <<" \"";
				moveCursorRelative(-2, 0);
				cout.flush();
			}
			cout << "  ";
			moveCursorRelative(-3, 0);
			cout << "\"";
			cout << "\n\n                  ";
			setTextColor(7);
			randomWaitInRange(5000, 12000);
			cout <<"You: ";
			SML::PlayEffect("Connection");
			setTextColor(15);
			cout << "\" \"";
			moveCursorRelative(-2, 0);
			startPosition = getCursorPosition();
			y = startPosition.Y;
			
			showCursor();
			setTextColor(15);
			
			
			
			isInChat = true;
			clearInputBuffer();
			while(isInChat){
				
				input = getValidInput();
				
				if(input!=8&&input!=13){
					position = getCursorPosition();
					if(position.X==startPosition.X+82){
						cout << "  ";
						moveCursor(startPosition.X, y+1);
						y++;
					}
					if(totalLenght<=499){
						cout<<input<<flush;
						if(input==' '){
							spaceEffect();
						}
						if(input!='.'){
							keyEffect();
						}else{
							SML::PlayEffect("key1");
						}
						cout <<" \"" << flush;
						moveCursorRelative(-2, 0);
						totalLenght++;
						text2 += input;
					}
				}
				
				if(input==8&&!text2.empty()){
					backspaceEffect();
					
					position = getCursorPosition();
					
					if(position.X != startPosition.X){
						cout<<input<<flush;
						
						cout <<" \" ";
						moveCursorRelative(-3, 0);
					}else{
						if(position.Y>startPosition.Y){
						cout << "  ";
						moveCursor(position.X+82, y-1);
						y--;
						cout<<input<<flush;
						cout <<" \" ";
						moveCursorRelative(-3, 0);
						}
						
					}
					totalLenght--;
					text2.pop_back();
				}
				
				if(input==13){
					SML::PlayEffect("enter");
					position = getCursorPosition();
					moveCursor(position.X, position.Y);
					cout <<"\" " << flush;
					hideCursor();
					isInChat = false;
					
					const char* appDataPath = getenv("APPDATA");

					string dosyaYolu = string(appDataPath) + "\\pathInfo.dat";
					ofstream dosya(dosyaYolu, ios::app);
					
					if (dosya.is_open()) { 
						dosya << "The users mesagge is : \"" << text2 <<"\""<< endl;
						dosya.close();
					} else {
						cerr << "Dosya açılamadı!" << endl;
					}
				}
				
				
			}

			randomWaitInRange(7000, 15000);
			bilmemne(0, 0, 0, 0, 0, 0, dosyaDisconnect2);
			portDeleted = true;
			changeAyar(1, 1);
		}

		
		if(!breadsEncryptedPort){
		
			bilmemne(300, 600, 0, 500, 0, 300, dosyaIsmi);
		
			cursorLimit = 3;

			displayMenu(s);
		
			if(s==1){
			
				bilmemne(300, 0, 0, 1000, 0, 300, dosyaA);
				
					lockTheAnswer(false);
				
				displayMenu(s);

				if(s==1){
					bilmemne(300, 600, 0, 500, 0, 300, dosyaAA);
					displayMenu(s);
					
						lockTheAnswer(false);
					
					
					if(s==1){
						AAA:
						if(!portDeleted&&AAADlock){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaAAAlocked);
							lockTheAnswer(true);
							displayMenu(s);
							if (s==1) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaAAAA);
								s = 0;
							}
							if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaAAAB);
								s = 0;
							}
							if (s==3) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaAAAC);
								s = 0;
							}
							SML::FadeOutMusic("breadmusic1", 5.0f);
							SML::UnloadMusic("breadmusic1");
							permissonD = false;
						}
						if(!portDeleted&&!AAADlock){	
							bilmemne(300, 600, 0, 500, 0, 300, dosyaAAA);
							displayMenu(s);
							if (s==1) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaAAAA);
								s = 0;
							}
							if (s==2) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaAAAB);
								s = 0;
							}
							if (s==3) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaAAAC);
								s = 0;
							}
							if (s==4) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaAAAD);
								s = 0;
							}
							permissonD = false;
						}
						if(portDeleted){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaAAA2);
							displayMenu(s);
							if (s==1) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaAAAA);
								s = 0;
							}
							if (s==2) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaAAAB);
								s = 0;
							}
							if (s==3) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaAAAC);
								s = 0;
							}
							if (s==4) {
								if(portDeleted&&progress==200){
									thread callThread(sendTwilioCall);
									bilmemne(300, 600, 0, 500, 0, 300, dosyaWrap);
									captureScreenshotToDesktop();
									callThread.join();
									SML::WaitMusic("breadmusic14");
									permissonD = false;
									s = 0;
								}else {
									bilmemne(300, 600, 0, 500, 0, 300, dosyaAAAD2);
									s = 0;
								}
							}
						}
					}
					if (s==2) {
						AAB:
						bilmemne(300, 600, 0, 500, 0, 300, dosyaAAB);
						displayMenu(s);
						
						if(s==1){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaAABA);
							s = 0;
						}
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaAABB);
							s = 0;
						}	
						if (s==3) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaAABC);
							s = 0;
						}	
						if (s==4) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaAABD);
							s = 0;
						}
					}
					if (s==3) {
						AAC:
						bilmemne(300, 600, 0, 500, 0, 300, dosyaAAC);
						s = 0;
					}	
					if (s==4) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaAAD);
						s = 0;
					}
				}

				if (s==2) {
					bilmemne(300, 600, 0, 500, 0, 300, dosyaAB);
					displayMenu(s);
					if(s==1){
						bilmemne(300, 600, 0, 500, 0, 300, dosyaABA);
						
							lockTheAnswer(false);
					
						displayMenu(s);
						if(s==1){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaABAA);
							s = 0;
						}
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaABAB);
							s = 0;
						}
						if (s==3) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaABAC);
							s = 0;
						}	
						if (s==4) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaABAD);
							s = 0;
						}
					}
					if (s==2) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaABB);
						lockTheAnswer(false);
						displayMenu(s);
						if(s==1){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaABBA);
							s = 0;
							displayMenu(s);
							if (s==1) {
								SML::StopMusic("theme1");
								bilmemne(300, 600, 0, 500, 0, 300, dosyaABBAA);
								SML::PlayFileOnce("breadmusic11.mp3"); //abba
								permissonD = false;
								s=0;
							}
							if (s==2) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaABBAB);
								s=0;
							}
							if (s==3) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaABBAC);
								s=0;
								lockTheAnswer(false);
								SML::PlayMusic("theme1");
								displayMenu(s);
								if (s==1) {
									bilmemne(300, 600, 0, 500, 0, 300, dosyaABBACA);
									s = 0;
								}
								if (s==2) {
									bilmemne(300, 600, 0, 500, 0, 300, dosyaABBACB);
									s = 0;
								}
								if (s==3) {
									bilmemne(300, 600, 0, 500, 0, 300, dosyaABBACC);
									SML::StopMusic("theme1");
									SML::PlayFileOnce("breadmusic11.mp3"); //abba
									permissonD = false;
									s = 0;
								}
								if (s==4) {
									bilmemne(300, 600, 0, 500, 0, 300, dosyaABBACD);
									s = 0;
								}
							}
							if (s==4) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaABBAD);
								s=0;
							}
						}
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaABBB);
							s = 0;
						}
						if (s==3) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaABBC);
							s = 0;
						}
						if (s==4) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaABBD);
							s = 0;
						}
					}
					if (s==3) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaABC);
						displayMenu(s);
						if(s==1){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaABCA);
							s = 0;
						}
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaABCB);
							s = 0;
						}
						if (s==3) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaABCC);
							s = 0;
						}	
						if (s==4) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaABCD);
							s = 0;
						}
					}
					if (s==4) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaABD);
						displayMenu(s);
						if(s==1){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaABDA);
							s = 0;
						}
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaABDB);
							s = 0;
						}
						if (s==3) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaABDC);
							s = 0;
						}	
						if (s==4) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaABDD);
							s = 0;
						}
					}		
				}
			
				if (s==3) {
					bilmemne(300, 600, 0, 500, 0, 300, dosyaAC);
					displayMenu(s);
					if(s==1){
						bilmemne(300, 600, 0, 500, 0, 300, dosyaACA);
						
							lockTheAnswer(false);
					
						displayMenu(s);
						if(s==1){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaACAA);
							s = 0;
						}
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaACAB);
							s = 0;
						}
						if (s==3) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaACAC);
							s = 0;
						}		
						if (s==4) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaUnlock);
							bilmemne(300, 600, 0, 500, 0, 300, dosyaACAD);
							s = 0;
						}
					}
					if (s==2) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaACB);
						s = 0;
					}
					if (s==3) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaACC);
						s = 0;
					}
					if (s==4) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaACD);
						displayMenu(s);
						if (s==1) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaACDA);
							s=0;
						}
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaACDB);
							s=0;
						}
						if (s==3) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaACDC);
							s=0;
						}
						if (s==4) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaACDD);
							displayMenu(s);
							if (s==1) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaACDDA);
								s=0;
							}
							if (s==2) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaACDDB);
								s=0;
							}
							if (s==3) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaACDDC);
								s=0;
							}
							if (s==4&&!ACDDDloop) {
				
								bilmemne(700, 1500, 0, 500, 0, 300, dosyaACDDD);
								displayMenu(s);
								if (s==1) {
									thread pitchTheme1thread(pitchTheme1);
									
									bilmemne(700, 740, 0, 500, 0, 300, dosyaACDDDA);
									
									
									
									displayMenu(s);
									
									
									if (s==1) {
										bilmemne(300, 740, 0, 500, 0, 300, dosyaDynamicAnswer);
										pitchTheme1thread.join();
										s=0;
										}
									if (s==2){
										bilmemne(300, 740, 0, 500, 0, 300, dosyaDynamicAnswer);
										pitchTheme1thread.join();
										s=0;
										}
									if (s==3){
										bilmemne(300, 740, 0, 500, 0, 300, dosyaDynamicAnswer);
										pitchTheme1thread.join();
										s=0;
									}
									if (s==4){
										thread pitchTheme2thread(pitchTheme2);
										
										bilmemne(300, 730, 0, 500, 0, 888, dosyaACDDDAD);
										displayMenu(s);
										
										
										
										if (s==1){
											bilmemne(300, 730, 0, 500, 0, 888, dosyaDynamicAnswer);
											pitchTheme1thread.join();
											pitchTheme2thread.join();
											s=0;
										}
										if (s==2){
											bilmemne(300, 730, 0, 500, 0, 888, dosyaDynamicAnswer);
											pitchTheme1thread.join();
											pitchTheme2thread.join();
											s=0;
										}
										if (s==3){
											bilmemne(300, 730, 0, 500, 0, 888, dosyaDynamicAnswer);
											pitchTheme1thread.join();
											pitchTheme2thread.join();
											s=0;
										}
										if (s==4) {
											thread darkthemeThread(darkthemes);
											bilmemne(300, 735, 0, 500, 0, 300, dosyaUnlock);
											AAADlock = false;
											ACDDDloop = true;
											//changeAyar(2, 1);
											bilmemne(300, 735, 0, 500, 0, 300, dosyaACDDDADD);
											centerText("Loading. . .");
											pitchTheme1thread.join();
											pitchTheme2thread.join();
											darkthemeThread.join();
											SML::UnloadMusic("breadmusic8");
											SML::UnloadMusic("breadmusic9");
											SML::UnloadMusic("breadmusic10");
											goto start;
										}
									}
								}
								if (s==2) {
									bilmemne(300, 740, 0, 500, 0, 300, dosyaDynamicAnswer);
									s=0;
								}
								if (s==3) {
									bilmemne(300, 740, 0, 500, 0, 300, dosyaDynamicAnswer);
									s=0;
								}
								if (s==4) {
									bilmemne(300, 740, 0, 500, 0, 300, dosyaDynamicAnswer);
									s=0;
								}
							}else if(s==4&&ACDDDloop) {
								while(true){
									bilmemne(300, 600, 0, 500, 0, 300, dosyaACDDD2);
									displayMenu(s);
									if(s==4){
										bilmemne(300, 600, 0, 500, 0, 300, dosyaACDDDD2);
										displayMenu(s);
										if(s==4){
											bilmemne(300, 600, 0, 500, 0, 300, dosyaACDDDDD);
											displayMenu(s);
											if(s==4){
												bilmemne(300, 600, 0, 500, 0, 300, dosyaACDDDDDD);
												displayMenu(s);
												if(s==4){
													bilmemne(300, 600, 0, 500, 0, 300, dosyaACDDDDDDD);
													displayMenu(s);
													if(s==4){
														bilmemne(300, 600, 0, 500, 0, 300, dosyaACDDDDDDDD);
														displayMenu(s);
														if(s==4){
															bilmemne(300, 600, 0, 500, 0, 300, dosyaACDDDDDDDDD);
															displayMenu(s);
															if(s==4){
																continue;
															}else{
																bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
																s=0;
																break;
															}
														}else{
															bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
															s=0;
															break;
														}
													}else{
														bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
														s=0;
														break;
													}
												}else{
													bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
													s=0;
													break;
												}
											}else{
												bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
												s=0;
												break;
											}
										}else{
											bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
											s=0;
											break;
										}
									}else{
										bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
										s=0;
										break;
									}
								}
							}
						}
					}
				}
				if (s==4) {
					bilmemne(300, 600, 0, 500, 0, 300, dosyaAD);
					displayMenu(s);
					if(s==1){
						bilmemne(300, 600, 0, 500, 0, 300, dosyaADA);
						displayMenu(s);
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaADAB);
							s = 0;
						}else{
							bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
							s=0;
						}
					}
					if (s==2) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaADB);
						s = 0;
					}
					if (s==3) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaADC);
						s = 0;
					}
					if (s==4) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaADD);
						s = 0;
					}
				}	
			}
			
			if(s==2){
				bilmemne(300, 600, 0, 500, 0, 300, dosyaB);
				
					lockTheAnswer(false);
			
				displayMenu(s);
			
				if (s==1) {
					bilmemne(300, 600, 0, 500, 0, 300, dosyaBA);
					
						lockTheAnswer(false);
				
					displayMenu(s);
					
					if(s==1){
						bilmemne(300, 600, 0, 500, 0, 300, dosyaBAA);
						displayMenu(s);
						s = 0;
			
					}
					if (s==2) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaBAB);
						displayMenu(s);

						if(s==1){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBABA);
							goto start;
						}
						if(s==4){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBABD);
							displayMenu(s);
							bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
							s==0;
						}
						else{
							bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
							s==0;
						}
					}
					if (s==3) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaBAC);
						displayMenu(s);
						if (s==1) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBACA);
							goto start;
						}
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBACB);
							goto start;
						}
						if (s==3) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBACC);
							displayMenu(s);
							bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
							s = 0;
						}
						if (s==4) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBACD);
							s = 0;
						}else{
							bilmemne(300, 1000, 0, 500, 0, 300, dosyaDynamicAnswer);
							s = 0;
						}
					}
					if (s==4) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaBAD);
						s = 0;
					}
					
				}
				if (s==2) {
					bilmemne(300, 600, 0, 500, 0, 300, dosyaBB);
					
						lockTheAnswer(false);
				
					displayMenu(s);
					
					if(s==1){
						bilmemne(300, 600, 0, 500, 0, 300, dosyaBBA);
						displayMenu(s);
						if(s==1){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBBAA);
							s = 0;
						}
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBBAB);
							
								lockTheAnswer(false);
							
							displayMenu(s);
							if (s==4) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaBBABD);
								s = 0;	
							}else{
								bilmemne(300, 1000, 0, 500, 0, 300, dosyaDynamicAnswer);
								s = 0;
							}
						}
						if (s==3) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBBAC);
							s = 0;
						}	
						if (s==4) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBBAD);
							displayMenu(s);
							if (s==4){
								bilmemne(300, 1000, 0, 500, 0, 300, dosyaBBADD);
								s = 0;
							}else{
								bilmemne(300, 1000, 0, 500, 0, 300, dosyaDynamicAnswer);
								s = 0;
							}
						}
					}
					if (s==2) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaBBB);
						displayMenu(s);
						if(s==1){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBBBA);
							s = 0;
						}
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBBBB);
							s = 0;
						}
						if(s==3){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBBBC);
							s = 0;
						}
						if (s==4) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBBBD);
							s = 0;
						}
					}
					if (s==3) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaBBC);
						
							lockTheAnswer(false);
						
						displayMenu(s);
					}
					if (s==4) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaBBD);
						displayMenu(s);
						if(s==1){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBBDA);
							s = 0;
						}	
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBBDB);
							s = 0;
						}
						if(s==3){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBBDC);
							s = 0;
						}
						if (s==4) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBBCD);
							s = 0;
						}
					}	
				}	
				if (s==3) {
					bilmemne(300, 600, 0, 500, 0, 300, dosyaBC);
					displayMenu(s);
					
					if(s==1){
						bilmemne(300, 600, 0, 500, 0, 300, dosyaBCA);
						displayMenu(s);
						if(s==1){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBCAA);
							s = 0;
						}
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBCAB);
							s = 0;
						}
						if(s==3){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBCAC);
							s = 0;
						}
						if (s==4) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBCAD);
							s = 0;
						}
					}
					if (s==2) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaBCB);
						displayMenu(s);
						if(s==1){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBCBA);
							s = 0;
						}
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBCBB);
							s = 0;
						}
						if(s==3){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBCBC);
							s = 0;
						}
						if (s==4) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBCBD);
							s = 0;
						}
					}
					if (s==3) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaBCC);
						lockTheAnswer(true);
						displayMenu(s);
						if(s==1){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBCCA);
							s = 0;
						}
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaBCCB);
							s = 0;
						}else{	
							bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
							s = 0;
						}
					}
					if (s==4) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaBCD);
						s=0;
					}
				}
				
				if (s==4) {
					bilmemne(300, 600, 0, 500, 0, 300, dosyaBD);
					s=0; 
				}
			}
		
			if(s==3){
				bilmemne(300, 600, 0, 500, 0, 300, dosyaC);
				
				lockTheAnswer(false);
				
				displayMenu(s);
				if (s==1) {
					bilmemne(300, 600, 850, 500, 0, 0, dosyaCA);
					displayMenu(s);
					if(s==1){
						bilmemne(300, 600, 0, 500, 0, 300, dosyaCAA);
						displayMenu(s);
						if(s==1){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCAAA);
							s = 0;
						}
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCAAB);
							s = 0;
						}
						if(s==3){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCAAC);
							s = 0;
						}
						if (s==4) {
							bilmemne(400, 700, 500, 1000, 700, 300, dosyaCAAD);
							permissonD = false;
							s = 0;
						}	
					}
					if (s==2) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaCAB);
						displayMenu(s);
						if(s==1){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCABA);
							s = 0;
						}
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCABB);
							s = 0;
						}
						if(s==3){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCABC);
							goto start;
						}
						if (s==4) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCABD);
							s = 0;
						}	
					}
					if (s==3) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaCAC);
						displayMenu(s);
						CAC:
				        
						if (s==1) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCACA);
							lockTheAnswer(false);
							displayMenu(s);
							if(s==1){
								goto AAA;
							}
							if(s==2){
								goto AAB;
							}
							if(s==3){
								goto AAC;
							}
							if(s==4){
								bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
								s = 0;
							}
						}
						if(s==2||s==3){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
							s = 0;
						}
						if(s==4){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCACD);
							displayMenu(s);
							if(s==1){
								bilmemne(300, 600, 0, 500, 0, 300, dosyaCACDA);
								goto start;
							}
							if(s==2){
								bilmemne(300, 600, 0, 500, 0, 300, dosyaCACDB);
								displayMenu(s);
								if(s==4){
									bilmemne(300, 600, 0, 500, 0, 300, dosyaCACDBD);
								}else{
									bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
									s = 0;
								}
							}
							if(s==3||s==4){
								bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
								s = 0;
							}
						}
					}
					if (s==4) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaCAD);
						displayMenu(s);
							bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
							s = 0;
					}
				}
				if (s==2) {
					bilmemne(300, 600, 0, 500, 0, 300, dosyaCB);
					displayMenu(s);
					if(s==1){
						bilmemne(300, 600, 0, 500, 0, 300, dosyaCBA);
						lockTheAnswer(true);
						displayMenu(s);
						if(s==1){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCBAA);
							s = 0;
						}
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCBAB);
							s = 0;
						}
						if(s==3){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCBAC);
							s = 0;
						}
						if (s==4) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCBAD);
							s = 0;
						}
					}
					if (s==2) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaCBB);
						s = 0;
					}
					if (s==3) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaCBC);
						lockTheAnswer(false);
						displayMenu(s);
						if(s==3){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCBCC);
							displayMenu(s);
							goto CAC;
						}else{
							bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
							s=0;
						}
					}
					if (s==4) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaCBD);
						displayMenu(s);
						if(s==3){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCBDC);
							s = 0;
						}	
						if (s==4) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCBDD);
							s = 0;
						}else{
							bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
							SML::FadeOutMusic("theme1", 4.0f);

							SML::PlayFileOnce("breadmusic7.mp3", false);
							SML::WaitMusic("breadmusic7");
							SML::UnloadMusic("breadmusic7");
							s = 0;
						}
					}
				}
				if (s==3) {
					bilmemne(300, 600, 0, 500, 0, 300, dosyaCC);
					lockTheAnswer(false);
					displayMenu(s);
					if(s==1){
						bilmemne(300, 600, 0, 500, 0, 300, dosyaCCA);
						displayMenu(s);
						if (s==1) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCCAA);
							continue;
						}if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCCAB);
							s = 0;
							
						}if (s==3) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCCAC);
							continue;
						}
						if (s==4) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCCAD);
							s = 0;
						}
					}
					if (s==2) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaCCB);
						
						displayMenu(s);
						if(s==1){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCCBA);
							s = 0;
						}	
						if (s==3) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCCBC);
							s = 0;
						}else{
							bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
							s = 0;	
						}
						
					}
					if (s==3) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaCCC);
						displayMenu(s);
						if (s==3) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCCCC);
							s = 0;
						}else{
							bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
							s = 0;
						}
					}
					if (s==4) {
						bilmemne(300, 600, 0, 500, 0, 300, dosyaCCD);
						displayMenu(s);
						if(s==1){
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCCDA);
							s = 0;
						}
						if (s==2) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCCDB);
							s = 0;
						}
						if (s==3) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCCDC);
							s = 0;
						}	
						if (s==4) {
							bilmemne(300, 600, 0, 500, 0, 300, dosyaCCDD);
							displayMenu(s);
							if(s==1){
								bilmemne(300, 600, 0, 500, 0, 300, dosyaCCDDA);
								s = 0;
							}
							if (s==2) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaCCDDB);
								s = 0;
							}
							if (s==3) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaCCDDC);
								s = 0;
							}	
							if (s==4) {
								bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
								s = 0;
							}	
						}
					}
				}
				if (s==4) {
					bilmemne(300, 600, 0, 500, 0, 300, dosyaCD);
					s=0;
				}
			}
		
			if (s==4) {
				if(offensiveAnswersLocked){
					bilmemne(300, 600, 0, 500, 0, 300, dosyaOffensiveUnlock);
					
					offensiveAnswersLocked = false;
					changeAyar(0, 2);
				}
				bilmemne(300, 600, 0, 500, 0, 300, dosyaDynamicAnswer);
			}
		}
		dosyaGonder();
		if(!returnToMenu){
			
			
			randomWaitInRange(1000, 6000);
		
			if (!breadsEncryptedPort&&permissonD){
				SML::StopMusic("theme1");
				SML::PlayFileOnce("breadmusic.mp3", false, 100.f, disconnectionPitch);
			}
			if (breadsEncryptedPort) SML::PlayEffectFile("effect4.wav");
			if (!breadsEncryptedPort) bilmemne(250, 250, 0, 0, 0, 0, dosyaDisconnect);
			pauseTheSystem();
		}
	}	
}
	