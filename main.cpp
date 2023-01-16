#include "TestLib.hpp"

#include <string>
#include <iostream>

int main() {
    const size_t i = 1;
    TestLib::StaticArray<int, i> arr;
    TestLib::Array<int> arr_1 {1, 2, 3};
    std::cout << TestLib::startarr("int") << arr << TestLib::endarr << std::endl;
    return 0;
}
