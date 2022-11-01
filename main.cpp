#include "TestLib.hpp"

#include <string>
#include <iostream>
#include <iomanip>

int main() {
    TestLib::Logger *logger = TestLib::initLogger("test.log.bin", true);
    TestLib::print(*logger, 10, 3.14);

    // std::string pattern = "#(###)-###-####";
    // std::string str;
    // std::cin >> str;
    // std::cout << std::boolalpha << TestLib::isValid(str, pattern) << std::endl;
    // int number;
    // std::cin >> number;
    // if (std::cin.fail()) {
    //     std::cout << "Incorrect input" << std::endl;
    //     std::cin.ignore(32000, '\n');
    //     std::cin.clear();
    // }
    // throw std::exception();


    TestLib::Node *list = nullptr;
    while (true) {
        int number;
        std::cout << "Введите число: ";
        std::cin >> number;
        if (number < 0) {
            break;
        }
        TestLib::addNode(&list, number);
    }

    TestLib::print(list, 2);

    return 0;
}

