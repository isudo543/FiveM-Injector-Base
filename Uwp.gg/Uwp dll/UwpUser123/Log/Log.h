#pragma once
#ifndef LOGGING_HXX
#define LOGGING_HXX

#include <cstdio>
#include <cstdarg>
#include <utility>
#include <Windows.h>

namespace Log {

    static constexpr const char* Reset = "\033[0m";

    static constexpr const char* ColInfoTag = "\033[38;2;107;255;122m";
    static constexpr const char* ColInfoText = "\033[38;2;229;229;229m";

    static constexpr const char* ColSuccessTag = "\033[38;2;107;255;122m";
    static constexpr const char* ColSuccessText = "\033[38;2;229;229;229m";

    static constexpr const char* ColErrorTag = "\033[38;2;255;106;106m";
    static constexpr const char* ColErrorText = "\033[38;2;229;229;229m";

    static constexpr const char* ColWarningTag = "\033[38;2;255;229;106m";
    static constexpr const char* ColWarningText = "\033[38;2;229;229;229m";

    static constexpr const char* ColDebugTag = "\033[38;2;105;153;255m";
    static constexpr const char* ColDebugText = "\033[38;2;229;229;229m";

    template<typename... A>
    inline void Info(const char* format, A&&... args) {
        char buf[2048];
        std::snprintf(buf, sizeof(buf), format, std::forward<A>(args)...);
        std::printf("%s[INFO]%s %s%s\n", ColInfoTag, ColInfoText, buf, Reset);
    }

    template<typename... A>
    inline void Success(const char* format, A&&... args) {
        char buf[2048];
        std::snprintf(buf, sizeof(buf), format, std::forward<A>(args)...);
        std::printf("%s[SUCCESS]%s %s%s\n", ColSuccessTag, ColSuccessText, buf, Reset);
    }

    template<typename... A>
    inline void Error(const char* format, A&&... args) {
        char buf[2048];
        std::snprintf(buf, sizeof(buf), format, std::forward<A>(args)...);
        std::printf("%s[ERROR]%s %s%s\n", ColErrorTag, ColErrorText, buf, Reset);
    }

    template<typename... A>
    inline void Warning(const char* format, A&&... args) {
        char buf[2048];
        std::snprintf(buf, sizeof(buf), format, std::forward<A>(args)...);
        std::printf("%s[WARNING]%s %s%s\n", ColWarningTag, ColWarningText, buf, Reset);
    }

    template<typename... A>
    inline void Debug(const char* format, A&&... args) {
        char buf[2048];
        std::snprintf(buf, sizeof(buf), format, std::forward<A>(args)...);
        std::printf("%s[DEBUG]%s %s%s\n", ColDebugTag, ColDebugText, buf, Reset);
    }

    inline void MsgBox(const char* title, const char* message) {
        MessageBoxA(nullptr, message, title, MB_OK);
    }

}

#endif
