#include "TestLib.hpp"

#include <string>
#include <iostream>

int main() {
    // TestLib::Human obj;
    TestLib::Human *array[] = {new TestLib::Employee("Alex", 15),
                               new TestLib::Manager("Alex", "DS")};
    std::cout << array[1]->className() << std::endl;
    delete array[1];
    return 0;
}
