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

        /*TODO*/ std::string className() const /*TODO*/ { return "Human"; }
    };

    class Employee : public Human {
    protected:
        uint64_t id;
        float m_salary;
    public:
        Employee() = default;
        Employee(const std::string &name, float salary);

        const char* className() const /*TODO*/ { return "Employee"; }
    };

    class Project {
    private:
        std::string m_name;
    public:
        Project(const std::string &name) : m_name(name) {}
    };

    class Manager : public Human {
    protected:
        uint64_t id;
        Project *m_proj = nullptr;
    public:
        Manager(const std::string &name, const std::string &project_name);

        std::string className() /*TODO*/ { return "Manager"; }

        ~Manager() {
            delete m_proj;
        }
    };

    class CEO /*TODO*/ : public Employee, public Manager {
    private:
        std::string m_company_name;
    public:
        CEO(const std::string &name, const std::string &project_name, float salary,
            const std::string &company_name);

        std::string className() const /*TODO*/ { return "CEO"; }
    };
}

#endif
