#ifndef TESTLIB_H
#define TESTLIB_H

#include <iostream>

namespace TestLib {
    class Human {
    protected:
        std::string m_name;
        // Human() = default;
        // explicit Human(const std::string &name);
    public:
        Human() = default;
        explicit Human(const std::string &name);

        virtual std::string className() const = 0;

        virtual Human* test() { return this; }

        virtual ~Human() {};
    };

    class Employee : public Human {
    protected:
        uint64_t id;
        float m_salary;
    public:
        Employee() = default;
        Employee(const std::string &name, float salary);

        Employee* test() override { return this; }

        std::string className() const override { return "Employee"; }
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

        std::string className() const override { return "Manager"; }

        ~Manager() {
            std::cout << "~Manager called" << std::endl;
            delete m_proj;
        }
    };

    class CEO final : public Employee, public Manager {
    private:
        std::string m_company_name;
    public:
        CEO(const std::string &name, const std::string &project_name, float salary,
            const std::string &company_name);

        std::string className() const override final { return "CEO"; }
    };
}

#endif
