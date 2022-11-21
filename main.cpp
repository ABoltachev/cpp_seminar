#include "TestLib.hpp"

#include <string>
#include <iostream>
#include <iomanip>

int main() {
    TestLib::List l {3};
    l = l;

    TestLib::Integer a = 5;
    TestLib::Integer b = a++;
    TestLib::Integer c = ++a;
    return 0;
}

