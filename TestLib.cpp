#include "TestLib.hpp"

namespace TestLib {
    void Employee::print() {
        std::cout << m_uid << ' ' << m_username << ' ' << m_name << ' ' << m_salary << std::endl;
    }

    void ImprovedEmployee::setUid(uint32_t uid) {
        m_uid = uid;
    }

    void ImprovedEmployee::setUserName(const std::string &username) {
        m_username = username;
    }

    void ImprovedEmployee::setName(const std::string &name) {
        m_name = name;
    }

    void ImprovedEmployee::setSalary(float salary) {
        m_salary = salary;
    }

    void ImprovedEmployee::print() {
        std::cout << m_uid << ' ' << m_username << ' ' << m_name << ' ' << m_salary << std::endl;
    }

    ImprovedEmployee::ImprovedEmployee(uint32_t uid, const std::string &username, const std::string &name, float salary)
        : m_uid(uid), m_username(username), m_name(name), m_salary(salary)
    {}

    ImprovedEmployee::ImprovedEmployee(const ImprovedEmployee &other)
        : m_uid(other.m_uid), m_username(other.m_username), m_name(other.m_name), m_salary(other.m_salary)
    {}

    void EmployeeList::addNewNode(Node *node) {
        if (m_head) {
            Node *cur_node = m_head;
            while (cur_node->m_next) {
                cur_node = cur_node->m_next;
            }
            cur_node->m_next = node;
        } else {
            m_head = node;
        }
    }

    void EmployeeList::addEmployee(const ImprovedEmployee &data) {
        Node *node = new Node;
        node->m_data = data;
        addNewNode(node);
    }

    void EmployeeList::addEmployee(uint32_t uid, const std::string &username, const std::string &name, float salary) {
        addEmployee(ImprovedEmployee(uid, username, name, salary));
    }
}
