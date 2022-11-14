#ifndef TESTLIB_H
#define TESTLIB_H

#include <iostream>
#include <fstream>
#include <string>

namespace TestLib {
    class Employee;

    class AddressBook {
    private:
        class Node {
        public:
            Employee m_data;
            Node *next = nullptr;

            Node() = default;
            Node(const Employee &data) : m_data(data) {}
        };
        Node *m_head;
        size_t m_size;
    public:
        AddressBook(const Employee &data);

        AddressBook(size_t size);

        Employee& at(size_t idx);

        void setEmployeeData(size_t idx, uint32_t uid, const std::string &username,
                             const std::string &name, float salary);

        void addEmployee();

        void addEmployee(uint32_t uid, const std::string &username,
                         const std::string &name, float salary);

        ~AddressBook();

        friend class Logger;
    };

    class Employee {
    private:
        uint32_t m_uid;
        std::string m_username;
        std::string m_name;
        float m_salary;
    public:
        Employee() = default;
        Employee(uint32_t uid, const std::string &username, const std::string &name, float salary);
        uint32_t getUid() const;
        std::string getUsername() const;
        std::string getName() const;
        float getSalaty() const;
        friend void AddressBook::setEmployeeData(size_t idx, uint32_t uid, const std::string &username,
                                                 const std::string &name, float salary);
    };


    class Logger {
    private:
        std::ofstream file;
    public:
        Logger(const std::string &log_file);

        void print(const AddressBook &address_book);
    };
}

#endif
