#pragma once
#ifndef LOGGING_HXX
#define LOGGING_HXX

#include <cstdio>
#include <cstdarg>
#include <utility>
#include <Windows.h>

namespace logging {

    static constexpr const char* reset = "\033[0m";

    static constexpr const char* col_info_tag = "\033[38;2;107;255;122m";
    static constexpr const char* col_info_text = "\033[38;2;229;229;229m";

    static constexpr const char* col_success_tag = "\033[38;2;107;255;122m";
    static constexpr const char* col_success_text = "\033[38;2;229;229;229m";

    static constexpr const char* col_error_tag = "\033[38;2;255;106;106m";
    static constexpr const char* col_error_text = "\033[38;2;229;229;229m";

    static constexpr const char* col_warning_tag = "\033[38;2;255;229;106m";
    static constexpr const char* col_warning_text = "\033[38;2;229;229;229m";

    static constexpr const char* col_debug_tag = "\033[38;2;105;153;255m";
    static constexpr const char* col_debug_text = "\033[38;2;229;229;229m";

    template<typename... A>
    inline void info(const char* format, A&&... args) {
        char buf[2048];
        std::snprintf(buf, sizeof(buf), format, std::forward<A>(args)...);
        std::printf("%s[INFO]%s %s%s\n", col_info_tag, col_info_text, buf, reset);
    }

    template<typename... A>
    inline void success(const char* format, A&&... args) {
        char buf[2048];
        std::snprintf(buf, sizeof(buf), format, std::forward<A>(args)...);
        std::printf("%s[SUCCESS]%s %s%s\n", col_success_tag, col_success_text, buf, reset);
    }

    template<typename... A>
    inline void error(const char* format, A&&... args) {
        char buf[2048];
        std::snprintf(buf, sizeof(buf), format, std::forward<A>(args)...);
        std::printf("%s[ERROR]%s %s%s\n", col_error_tag, col_error_text, buf, reset);
    }

    template<typename... A>
    inline void warning(const char* format, A&&... args) {
        char buf[2048];
        std::snprintf(buf, sizeof(buf), format, std::forward<A>(args)...);
        std::printf("%s[WARNING]%s %s%s\n", col_warning_tag, col_warning_text, buf, reset);
    }

    template<typename... A>
    inline void debug(const char* format, A&&... args) {
        char buf[2048];
        std::snprintf(buf, sizeof(buf), format, std::forward<A>(args)...);
        std::printf("%s[DEBUG]%s %s%s\n", col_debug_tag, col_debug_text, buf, reset);
    }

    inline void message_box(const char* title, const char* message) {
        MessageBoxA(nullptr, message, title, MB_OK);
    }

}

#endif