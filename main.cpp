#include "TestLib.hpp"

#include <string>
#include <iostream>

int main() {
    // TestLib::Human obj;
    std::string test;
    TestLib::Human *array[] = {new TestLib::Employee("Alex", 15)};

    try {
        std::cin >> *array[0];
    }
    catch (TestLib::IncorrectID &ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (TestLib::ValueError &ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cin >> test;
    std::cout << *array[0] << std::endl;
    std::cout << test << std::endl;
    return 0;
}
