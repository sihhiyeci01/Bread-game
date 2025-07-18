#define OCR_NORMAL 32512
#include <windows.h>
#include <iostream>
#include <tlhelp32.h>
#include <string>
#include <thread>
#include <atomic>

using namespace std;

// GLOBAL HOOK HANDLE VE THREAD ID'LERİ
HHOOK mouseHook = nullptr;
HHOOK keyboardHook = nullptr;
std::atomic<bool> shiftBlockEnabled{ true };  
std::atomic<bool> running{ true };
std::atomic<DWORD> mouseHookThreadId{0};
std::atomic<DWORD> keyboardHookThreadId{0};

HANDLE hShiftToggleEvent = nullptr;

DWORD WINAPI ShiftToggleThread(LPVOID){
    while (running.load()) {
        DWORD res = WaitForSingleObject(hShiftToggleEvent, 100);   // 0.1 sn’de bir çıkış kontrolü
        if (res == WAIT_OBJECT_0) {
            shiftBlockEnabled.store(!shiftBlockEnabled.load());    // Tersine çevir
        }
    }
    return 0;
}

// BREAD.EXE KONTROLÜ İÇİN FONKSİYONLAR
bool isProcessRunning(const std::wstring& processName) {
    bool found = false;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) return false;

    PROCESSENTRY32W entry;
    entry.dwSize = sizeof(PROCESSENTRY32W);

    if (Process32FirstW(snapshot, &entry)) {
        do {
            if (processName == entry.szExeFile) {
                found = true;
                break;
            }
        } while (Process32NextW(snapshot, &entry));
    }
    CloseHandle(snapshot);
    return found;
}

bool isBreadActiveWindow() {
    HWND foreground = GetForegroundWindow();
    if (!foreground) return false;

    DWORD pidForeground = 0;
    GetWindowThreadProcessId(foreground, &pidForeground);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) return false;

    PROCESSENTRY32W entry;
    entry.dwSize = sizeof(PROCESSENTRY32W);
    bool result = false;

    if (Process32FirstW(snapshot, &entry)) {
        do {
            if (entry.th32ProcessID == pidForeground) {
                if (std::wstring(entry.szExeFile) == L"Bread.exe") {
                    result = true;
                    break;
                }
            }
        } while (Process32NextW(snapshot, &entry));
    }
    CloseHandle(snapshot);
    return result;
}

// GÖRÜNMEZ İMLEÇ
HCURSOR createInvisibleCursor() {
    constexpr int width  = 8;
    constexpr int height = 8;
    constexpr int bytesPerRow = ((width + 15) / 16) * 2;
    BYTE ANDmask[height * bytesPerRow];
    BYTE XORmask[height * bytesPerRow];
    memset(ANDmask, 0xFF, sizeof ANDmask);
    memset(XORmask, 0x00, sizeof XORmask);
    return CreateCursor(
        nullptr,
        0, 0,
        width, height,
        ANDmask, XORmask
    );
}

// MOUSE HOOK
LRESULT CALLBACK LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        if (wParam == WM_MOUSEWHEEL) {
            MSLLHOOKSTRUCT* pMouseStruct = (MSLLHOOKSTRUCT*)lParam;
            if (isBreadActiveWindow()) {
                return 1;
            }
        }
    }
    return CallNextHookEx(mouseHook, nCode, wParam, lParam);
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

void MouseHookThread() {
    mouseHookThreadId = GetCurrentThreadId();
    mouseHook = SetWindowsHookEx(WH_MOUSE_LL, LowLevelMouseProc, nullptr, 0);
    if (mouseHook == nullptr) {
        std::cerr << "ERROR : mouse hook kurulamadı!\n";
        return;
    }
    MSG msg;
    while (running.load()) {
        if (GetMessage(&msg, nullptr, 0, 0) > 0) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    UnhookWindowsHookEx(mouseHook);
}

// KLAVYE HOOK
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*)lParam;
        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
            if (isBreadActiveWindow()) {
                // CTRL tuşları
                if (p->vkCode == VK_CONTROL || p->vkCode == VK_LCONTROL || p->vkCode == VK_RCONTROL) return 1;
                // SHIFT tuşları
                if (p->vkCode == VK_SHIFT   || p->vkCode == VK_LSHIFT   || p->vkCode == VK_RSHIFT)   return 1;
                // CTRL ile herhangi bir tuş
                if ((GetAsyncKeyState(VK_CONTROL) & 0x8000)) return 1;
                // SHIFT ile herhangi bir tuş
                if ((GetAsyncKeyState(VK_SHIFT)   & 0x8000)) return 1;
            }
        }
    }
    return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}

void KeyboardHookThread() {
    keyboardHookThreadId = GetCurrentThreadId();
    keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, nullptr, 0);
    if (keyboardHook == nullptr) {
        std::cerr << "ERROR: Keyboard hook kurulamadı!\n";
        return;
    }
    MSG msg;
    while (running.load()) {
        if (GetMessage(&msg, nullptr, 0, 0) > 0) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    UnhookWindowsHookEx(keyboardHook);
}

// ANA PROGRAM (wWinMain)
int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int) {
    thread hookThread(MouseHookThread);
    thread keyboardThread(KeyboardHookThread); // KLAVYE THREAD'I EKLENDİ
	disableConsoleHotkeys();
    const std::wstring targetProcess = L"Bread.exe";
    bool cursorHidden = false;
    HCURSOR hInvisible = nullptr;
    int centerX = GetSystemMetrics(SM_CXSCREEN) / 2;
    int centerY = GetSystemMetrics(SM_CYSCREEN) / 2;

    while (isProcessRunning(targetProcess)) {
        bool breadActive = isBreadActiveWindow();
        if (breadActive) {
            POINT pt;
            GetCursorPos(&pt);
            if (pt.x != centerX || pt.y != centerY) {
                SetCursorPos(centerX, centerY);
            }
        }
        // Cursor gizleme/geri yükleme
        if (breadActive && !cursorHidden) {
            hInvisible = createInvisibleCursor();
            SetSystemCursor(hInvisible, OCR_NORMAL);
            cursorHidden = true;
        } else if (!breadActive && cursorHidden) {
            SystemParametersInfo(SPI_SETCURSORS, 0, 0, 0);
            if (hInvisible) {
                DestroyCursor(hInvisible);
                hInvisible = nullptr;
            }
            cursorHidden = false;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(breadActive ? 80 : 500));
    }

    // Kapanışta varsayılan imleç geri yükle
    if (cursorHidden) {
        SystemParametersInfo(SPI_SETCURSORS, 0, 0, 0);
        if (hInvisible) {
            DestroyCursor(hInvisible);
            hInvisible = nullptr;
        }
    }
    running = false;
    PostThreadMessage(mouseHookThreadId, WM_QUIT, 0, 0);
    PostThreadMessage(keyboardHookThreadId, WM_QUIT, 0, 0);

    hookThread.join();
    keyboardThread.join();
    return 0;
}
