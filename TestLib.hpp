#ifndef TESTLIB_H
#define TESTLIB_H

#include <iostream>
#include <fstream>
#include <string>

namespace TestLib {
    struct Logger {
        std::ofstream log_file;
        bool is_binary;
    };

    Logger* initLogger(/*TODO тут должна быть строка*/);

    template<typename... Args>
    char* getStr(Args... args);

    template<typename Head, typename... Tail>
    char* getStr(const Head &head, Tail... tail) {
        // TODO
    }

    template<>
    char* getStr() {
        // TODO
    }

    template<typename... Args>
    void print(const Logger &logger, Args... args);

    template<typename Head, typename... Tail>
    void print(const Logger &logger, const Head &head, Tail... tail) {
        // TODO
    }

    template<>
    void print(const Logger &logger) {
        // TODO
    }

    void readLogFile(/*TODO тут должна быть строка*/);
}

#endif
