#ifndef TESTLIB_H
#define TESTLIB_H

#include <iostream>
#include <fstream>
#include <string>

namespace TestLib {
    class Employee {
    private:
        uint32_t m_uid;
        std::string m_username;
        std::string m_name;
        float m_salary;

    public:
        uint32_t getUid(); //
        std::string getUsername(); //
        std::string getName(); //
        float getSalaty(); //
    };

    class AddressBook {
    private:
        Node *m_head;
        size_t m_size;
    public:
        AddressBook(size_t size);

        Employee& at(size_t idx);

        void setEmployeeData();
    };

    class Logger {
    private:
        std::ofstream;
    public:
        Logger(const std::string &log_file);

        void print();
    };
}

#endif
