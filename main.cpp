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
    TestLib::ImprovedEmployee improved_employee_1;
    improved_employee_1.setUid(uid);
    improved_employee_1.setUserName(username);
    improved_employee_1.setName(name);
    improved_employee_1.setSalary(salary);
    improved_employee_1.print();

    TestLib::ImprovedEmployee improved_employee_2 {improved_employee_1};
    improved_employee_2.print();

    TestLib::EmployeeList list;
    list.addEmployee(improved_employee_1);
    list.creatNewEmployee(uid + 10, username, name, salary);
    list.print();
    return 0;
}

