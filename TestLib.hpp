#ifndef TESTLIB_H
#define TESTLIB_H

#include <iostream>

namespace TestLib {
    class List {
    private:
        int *m_list = nullptr;
        size_t m_size = 0;

        // List(const List&); // Запрещает использование конструктора копирования

        int& at(size_t idx); // Нужно добавить соотсетствующий оператор
    public:
        List() = default;
        explicit List(size_t size); // Запрещает запись List l = 10;
        List(const List&) = delete; // Запрещает использование конструктора копирования

        void append(int data);
        void extend(const List &another);
        List operator+(const List &another) const;

        int& operator[](size_t idx);
        // List l = {1, 2, 3};
        // l[2] = 5;
        const int& operator[](size_t idx) const;
        // void func(const List &l) { l[2];}

        bool operator==(const List &another) const;
        bool operator!=(const List &another) const;

        List& operator=(const List &another);
        // List l = {1, 2, 3};
        // l = l;

        friend std::ostream& operator<<(std::ostream &out, const List &list);
    };

    class Integer {
    private:
        int m_data;
    public:
        Integer();
        Integer(int data);

        Integer operator+(const Integer &rgh) const; // Integer + Integer
        Integer operator+(int rgh) const; // Integer + int
        // friend Integer operator+(int lft, const Integer &rgh); // int + Integer

        Integer& operator++(); // Префикс
        Integer operator++(int); // Постфикс
        Integer& operator--(); // Префикс
        Integer operator--(int); // Постфикс
        operator int() const;
        // Печать на экран и ввод с консоли
    };

    Integer operator+(int lft, const Integer &rgh);
}

#endif
