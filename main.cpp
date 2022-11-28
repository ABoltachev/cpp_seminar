#include "TestLib.hpp"

#include <string>
#include <iostream>
#include <iomanip>

int main() {
    TestLib::Human *ptr = new TestLib::Employee(); // Не теряем данные из Employee
    TestLib::Employee emp;
    TestLib::Human &ref = emp; // Не теряем данные из Employee
    TestLib::Human obj = emp;  // Теряем данные из Employee
    return 0;
}
