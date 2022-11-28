#ifndef TESTLIB_H
#define TESTLIB_H

#include <iostream>

namespace TestLib {
    class Human {
    protected:
        std::string m_name;
    public:
        Human() = default;
        explicit Human(const std::string &name);

        std::string className() const { return "Human"; }

        bool isHumanClass() const { return true; }
    };

    class Employee : public Human {
    private:
        using Human::isHumanClass;
    protected:
        uint64_t id;
        float m_salary;
    public:
        Employee() = default;
        Employee(const std::string &name, float salary);

        std::string className() const { return "Employee"; }
    };

    class Manager : public Human {
    protected:
        uint64_t id;
        std::string m_project_name;
    public:
        Manager(const std::string &name, const std::string &project_name);

        std::string className() const { return "Manager"; }
        bool isHumanClass() = delete;
    };

    class CEO : public Employee, public Manager {
    private:
        std::string m_company_name;
    public:
        CEO(const std::string &name, const std::string &project_name, float salary,
            const std::string &company_name);

        void test() {
            Employee::m_name = "";
            Manager::m_name = "";

            Employee::id = 0;
            Manager::id = 1;
        }

        std::string className() const { return "CEO"; }
    };
}

#endif
