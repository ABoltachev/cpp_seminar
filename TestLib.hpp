#ifndef TESTLIB_H
#define TESTLIB_H

#include <iostream>
#include <stdexcept>

namespace TestLib {
    class ValueError : public std::runtime_error {
    public:
        ValueError(const std::string &msg) : std::runtime_error(msg) {}
        // const char* what() const throw() override; не нужен, так как уже определен в базовом
    };

    class IncorrectID : public ValueError {
    public:
        IncorrectID() : ValueError("Incorrect ID") {}
    };


    class Human {
    protected:
        std::string m_name;
    public:
        Human() = default;
        explicit Human(const std::string &name);

        virtual std::string className() const = 0;

        virtual Human* test() { return this; }

        virtual ~Human() {};

        virtual std::ostream& print(std::ostream &out) const;
        virtual std::istream& input(std::istream &in) = 0;

        friend std::ostream& operator<<(std::ostream &out, const Human &p);
        friend std::istream& operator>>(std::istream &in, Human &p);
    };

    class Employee : virtual public Human {
    protected:
        uint64_t id;
        float m_salary;
    public:
        Employee() = default;
        Employee(const std::string &name, float salary);

        Employee* test() override { return this; }

        std::string className() const override { return "Employee"; }

        std::ostream& print(std::ostream &out) const override;

        std::istream& input(std::istream& in) override;
    };

    class Project {
    private:
        std::string m_name;
    public:
        Project(const std::string &name) : m_name(name) {}
    };

    class Manager : virtual public Human {
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
