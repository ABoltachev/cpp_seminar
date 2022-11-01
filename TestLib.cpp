#include "TestLib.hpp"

#include <cassert>

namespace TestLib {
    Logger* initLogger(const std::string &file_path, bool is_binary) {
        std::ios::openmode mode = (is_binary) ? std::ios::out | std::ios::binary : std::ios::out;

        // Logger *logger = new Logger {std::ofstream(file_path, mode), is_binary};
        Logger *logger = new Logger;
        logger->is_binary = is_binary;
        logger->log_file.open(file_path, mode);
        // if (logger->log_file.is_open())
        if (!logger->log_file) {
            delete logger;
            logger = nullptr;
        }
        return logger;
    }

    // # - число
    // & - буквы
    // @ - @

    bool isValidChar(char c, char pattern) {
        switch (pattern) {
        case '#':
            return isdigit(c);
        case '&':
            return isalpha(c);
        default:
            return c == pattern;
        }
        return true;
    }

    bool isValid(const std::string &str, const std::string &pattern) {
        assert(str.length() == pattern.length());
        for (int i = 0; i < str.length(); i++) {
            if (!isValidChar(str[i], pattern[i])) {
                return false;
            }
        }
        return true;
    }
}
