#include "TestLib.hpp"

int main() {
    TestLib::Point a {10, 25}, b {15, 10};
    TestLib::coordsVector(a, b);

    TestLib::print(10, 25.);
    return 0;
}

