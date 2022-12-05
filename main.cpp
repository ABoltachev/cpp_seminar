#include "TestLib.hpp"

#include <string>
#include <iostream>

int main() {
    TestLib::Human *array[] = {new TestLib::Employee("Alex", 15),
                               new TestLib::Manager("Alex", "DS")};
    return 0;
}
