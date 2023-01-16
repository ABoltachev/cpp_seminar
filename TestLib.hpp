#ifndef TESTLIB_H
#define TESTLIB_H

#include <iostream>
#include <string>

namespace TestLib {
    template<class Data>
    class Array {
    private:
        size_t m_size = 0;
        Data *m_arr = nullptr;
    public:
        Array() = default;
        explicit Array(size_t size);
        Array(const std::initializer_list<Data> &init_list);
    };

    template<class Data, size_t size>
    class StaticArray;

    template<class Data, size_t size>
    std::ostream& operator<<(std::ostream &out, const StaticArray<Data, size> &obj);

    template<class Data, size_t size>
    class StaticArray {
    private:
        Data m_arr[size];
    public:
        StaticArray() = default;

        friend std::ostream& operator<< <>(std::ostream &out, const StaticArray<Data, size> &obj);
    };

    class startarr {
    private:
        std::string m_type_name;
    public:
        startarr(const std::string &type_name) : m_type_name(type_name) {}

        friend std::ostream& operator<<(std::ostream &out, const startarr &manip) {
            return out << "Array<" << manip.m_type_name << ">: [";
        }
    };

    std::ostream& endarr(std::ostream &out) {
        return out << ']';
    }
}

#include "TestLib.tpp"

#endif
