#ifndef TESTLIB_H
#define TESTLIB_H

#include <iostream>

namespace TestLib {
    template<typename Data>
    Data max(Data a, Data b) {
        return (a > b) ? a : b;
    }

    struct Point {
        int x;
        int y;
    };

    static Point* coordsVector_impl(const Point& start, const Point& end);

    Point coordsVector(const Point& start, const Point& end);

    template<typename... Args>
    void print(Args... args);

    template<typename Head, typename... Tail>
    void print(const Head &head, Tail... tail) {
        std::cout << head << ' ';
        print(tail...);
    }

    template<>
    void print() {
        std::cout << std::endl;
    }
}

#endif
