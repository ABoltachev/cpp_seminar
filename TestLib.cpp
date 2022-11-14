#include "TestLib.hpp"

#include <cassert>

namespace TestLib {
    AddressBook::AddressBook(const Employee &data) {
        m_head = new Node(Employee(data.getUid(), data.getUsername(), data.getName(), data.getSalaty()));
        m_size = 1;
    }

    AddressBook::AddressBook(size_t size) {
        for (size_t i = 0; i < size; i++) {
            addEmployee();
        }
    }

    void AddressBook::addEmployee() {
        m_size++;
        if (!m_head) {
            m_head = new Node;
            return;
        }
        Node *cur_node = m_head;
        while (cur_node->next) {
            cur_node = cur_node->next;
        }
        cur_node->next = new Node;
    }

    void AddressBook::setEmployeeData(size_t idx, uint32_t uid, const std::string &username,
                                      const std::string &name, float salary) {
        Employee data = at(idx);
        data.m_uid = uid;
        data.m_username = username;
        data.m_name = name;
        data.m_salary = salary;
    }

    Employee& AddressBook::at(size_t idx) {
        assert(idx >= m_size);

        Node *cur_node = m_head;
        for (size_t i = 0; i < idx; i++) {
            cur_node = cur_node->next;
        }
        return cur_node->m_data;
    }
}
