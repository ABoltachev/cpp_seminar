#ifndef TESTLIB_H
#define TESTLIB_H

#include <iostream>
#include <fstream>
#include <string>

namespace TestLib {
    class Employee {
    public: // По умолчанию private
        uint32_t m_uid;
        std::string m_username;
        std::string m_name;
        float m_salary;

        void print();
    };

    class ImprovedEmployee {
    private:
        uint32_t m_uid;
        std::string m_username;
        std::string m_name;
        float m_salary;
    public:
        ImprovedEmployee() = default; // Генерирует определение конструктора заложенное в компиляторе
        ImprovedEmployee(uint32_t uid, const std::string &username, const std::string &name, float salary);
        ImprovedEmployee(const ImprovedEmployee &other);

        void setUid(uint32_t uid);
        void setUserName(const std::string &username);
        void setName(const std::string &name);
        void setSalary(float salary);

        void print();
    };

    class EmployeeList {
    private:
        struct Node {
            ImprovedEmployee m_data;
            Node *m_next = nullptr;
        } *m_head = nullptr;
        void addNewNode(Node *node);
    public:
        void addEmployee(const ImprovedEmployee &data);
        void addEmployee(uint32_t uid, const std::string &username, const std::string &name, float salary);
    };
}

#endif
