#include "TestLib.hpp"

namespace TestLib {
    Human::Human(const std::string &name) : m_name(name) {}

    Employee::Employee(const std::string &name, float salary) : m_salary(salary), Human(name) {}

    Manager::Manager(const std::string &name, const std::string &project_name) : Human(name) {
        m_proj = new Project(project_name);
    }

    CEO::CEO(const std::string &name, const std::string &project_name, float salary,
             const std::string &company_name) : m_company_name(company_name), Employee(name, salary),
                                                Manager(name, project_name) {}

    std::string TestLib::Human::className() const {
        return "Human";
    }

    std::ostream& Human::print(std::ostream &out) const {
        out << "Class human" << std::endl;
        return out << m_name;
    }

    std::ostream& operator<<(std::ostream &out, const Human &p) {
        return p.print(out);
    }

    std::istream& operator>>(std::istream &in, Human &p) {
        return p.input(in);
    }

    std::ostream& Employee::print(std::ostream &out) const {
        return out << m_name << ' ' << id << ' ' << m_salary;
    }

    std::istream& Employee::input(std::istream& in) {
        in >> id;
        if (in.fail()) {
            in.clear();
            in.ignore(32000, '\n');
            throw IncorrectID();
        }
        if (id > 0) {
            return in;
        }
        in >> m_name;
        in >> m_salary;
        if (in.fail()) {
            in.clear();
            in.ignore(32000, '\n');
            throw ValueError("Incorrect salary");
        }
        return in;
    }
}
