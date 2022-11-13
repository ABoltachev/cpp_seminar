#include "TestLib.hpp"

#include <string>
#include <iostream>
#include <iomanip>

int main() {
    uint32_t uid = 10;
    std::string username = "Anchovy";
    std::string name = "Aleksandr Boltachev";
    float salary = 500.;
    TestLib::Employee employee {uid, username, name, salary};
    employee.print();
    // TestLib::ImprovedEmployee employee {uid, username, name, salary}; не должно работать
    TestLib::ImprovedEmployee improved_employee_1; // Если мы определили любой конструктор, то конструктор без аргументов не генерируется автоматически
    improved_employee_1.setUid(uid);
    improved_employee_1.setUserName(username);
    improved_employee_1.setName(name);
    improved_employee_1.setSalary(salary);
    improved_employee_1.print();

    TestLib::ImprovedEmployee improved_employee_2 {improved_employee_1};
    improved_employee_2.print();

    TestLib::EmployeeList list;
    // TestLib::EmployeeList::Node node; нет доступа, так как структура Node имеет модификатор доступа private
    list.addEmployee(improved_employee_1);
    list.addEmployee(uid + 10, username, name, salary);
    // list.print();
    return 0;
}

