#include "TestLib.hpp"

#include <cassert>

namespace TestLib {
    List::List(size_t size) : m_list(new int[size]), m_size(size) {}

    List& List::operator=(const List &another) {
        if (this != &another) {
            delete m_list;
            m_list = new int[another.m_size];
            for (size_t i = 0; i < another.m_size; i++) {
                m_list[i] = another.m_list[i];
            }
            m_size = another.m_size;
        }
        return *this;
    }

    Integer::Integer(int data) : m_data(data) {}

    Integer& Integer::operator++() {
        m_data++;
        return *this;
    }
    Integer& Integer::operator--() {
        m_data--;
        return *this;
    }

    Integer Integer::operator++(int) {
        Integer tmp {m_data};
        m_data++;
        return tmp;
    }

    Integer Integer::operator--(int) {
        Integer tmp {m_data};
        m_data--;
        return tmp;
    }

    Integer::operator int() const{
        return m_data;
    }

    Integer operator+(int lft, const Integer &rgh) {
        return {lft + rgh};
    }
}
