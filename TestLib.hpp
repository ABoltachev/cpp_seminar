#ifndef TESTLIB_H
#define TESTLIB_H

#include <iostream>

namespace TestLib {
    class Human {
    // TODO
        std::string m_name;
    public:
        /*TODO*/ Human(const std::string &name);

        std::string className() { return "Human"; } // TODO

        bool isHumanClass() { return true; } // TODO
    };

    class Employee /* TODO */ {
    // TODO
        float m_salary;
    public:
        Employee(const std::string &name, float salary);

        std::string className() { return "Employee"; } // TODO
    };

    class Manager /* TODO */ {
    // TODO
        std::string m_project_name;
    public:
        Manager(const std::string &name, const std::string &project_name);

        std::string className() { return "Manager"; } // TODO
    };

    class CEO : public Human {
    // TODO
        std::string m_company_name;
    public:
        CEO(const std::string &name, const std::string &project_name, float salary,
            const std::string &company_name);

        std::string className() { return "CEO"; } // TODO
    };
}

#endif
