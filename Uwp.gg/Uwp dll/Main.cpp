#include <Windows.h>
#include <cstdio>
#include "UwpUser123/Log/Log.h"
#include <string>

void AllocateConsole() {
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    freopen_s(&f, "CONIN$", "r", stdin);
    freopen_s(&f, "CONOUT$", "w", stderr);
    SetConsoleTitleA("Uwp console");
}

void set_console_ansi() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD m = 0;
    GetConsoleMode(h, &m);
    SetConsoleMode(h, m | ENABLE_VIRTUAL_TERMINAL_PROCESSING | ENABLE_PROCESSED_OUTPUT);
}

void set_font_size(int size) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX cfi{};
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(h, FALSE, &cfi);
    cfi.dwFontSize.Y = size;
    SetCurrentConsoleFontEx(h, FALSE, &cfi);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        AllocateConsole();
        set_console_ansi();
        set_font_size(14);
        Log::Info("Uwp.gg injected successfully starting dumping process");
        Log::MsgBox("Draco boyzzz", "injected");
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

