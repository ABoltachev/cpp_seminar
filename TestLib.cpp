#include "TestLib.hpp"

namespace TestLib {
    Human::Human(const std::string &name) : m_name(name) {}

    Employee::Employee(const std::string &name, float salary) : m_salary(salary), Human(name) {}

    Manager::Manager(const std::string &name, const std::string &project_name) : m_project_name(project_name), Human(name) {}

    CEO::CEO(const std::string &name, const std::string &project_name, float salary,
             const std::string &company_name) : m_company_name(company_name), Employee(name, salary),
                                                Manager(name, project_name) {}
}
