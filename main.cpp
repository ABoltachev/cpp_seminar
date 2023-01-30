#include "TestLib.hpp"

#include <string>
#include <iostream>

int main() {
    AutoPtr<int> ptr_2;
    {
        AutoPtr<int> ptr_1 {3};
        ptr_2 = std::move(ptr_1);
    }
    return 0;
}
