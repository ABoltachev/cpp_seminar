#ifndef TESTLIB_TPP
#define TESTLIB_TPP

template <typename Data>
AutoPtr<Data>::AutoPtr(Data *ptr) : m_ptr(ptr), m_size(0) {}


template <typename Data>
AutoPtr<Data>::AutoPtr(size_t size) : m_size(size) {
    m_ptr = new Data[size];
}

template <typename Data>
AutoPtr<Data>::AutoPtr(AutoPtr &&obj) : m_ptr(obj.m_ptr), m_size(obj.m_size) {
    obj.m_ptr = nullptr;
    obj.m_size = 0;
}

template <typename Data>
AutoPtr<Data>::~AutoPtr() {
    if (m_size > 0) {
        delete [] m_ptr;
    } else {
        delete m_ptr;
    }
}

template <typename Data>
size_t AutoPtr<Data>::size() const {
    return m_size;
}

template <typename Data>
Data& AutoPtr<Data>::operator*() const { return *m_ptr; }

template <typename Data>
Data* AutoPtr<Data>::operator->() const { return m_ptr; }

template <typename Data>
void AutoPtr<Data>::checkArray(size_t idx) const {
    if (m_size == 0) {
        throw std::logic_error("AutoPtr isn't array");
    }
    if (!m_ptr) {
        throw std::logic_error("AutoPtr is null");
    }
    if (idx >= m_size) {
        throw std::out_of_range("idx incorrect");
    }
}

template <typename Data>
Data& AutoPtr<Data>::operator[](size_t idx) {
    checkArray(idx);
    return m_ptr[idx];
}

template <typename Data>
const Data& AutoPtr<Data>::operator[](size_t idx) const {
    checkArray(idx);
    return m_ptr[idx];
}

template <typename Data>
AutoPtr<Data>& AutoPtr<Data>::operator=(AutoPtr &&obj) {
    if (&obj != this) {
        m_ptr = obj.m_ptr;
        m_size = obj.m_size;

        obj.m_ptr = nullptr;
        obj.m_size = 0;
    }

    return *this;
}

template <typename Data>
AutoPtr<Data>::operator bool() const {
    return m_ptr != nullptr;
}

#endif
