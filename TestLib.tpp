#ifndef TESTLIB_TPP
#define TESTLIB_TPP

namespace TestLib {
    template<class Data>
    Array<Data>::Array(size_t size) : m_arr(new Data[size]), m_size(size) {}

    template<class Data>
    Array<Data>::Array(const std::initializer_list<Data> &init_list) : Array(init_list.size()) {
        auto it = init_list.begin();
        for (size_t i = 0; i < m_size; i++) {
            m_arr[i] = *(it + i);
        }
    }

    template<class Data, size_t size>
    std::ostream& operator<<(
        std::ostream &out, const StaticArray<Data, size> &obj
    ) {
        for (int i = 0; i < size; i++) {
            out << obj.m_arr[i];
        }
        return out;
    }

    template<size_t size>
    std::ostream& operator<<(
        std::ostream &out, const StaticArray<char, size> &obj
    ) {
        for (int i = 0; i < size; i++) {
            out << static_cast<int>(obj.m_arr[i]);
        }
        return out;
    }
}

#endif
