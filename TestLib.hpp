#ifndef TESTLIB_H
#define TESTLIB_H

#include <stdexcept>

template <typename Data>
class AutoPtr {
private:
    Data *m_ptr = nullptr;
    size_t m_size = 0;

    void checkArray(size_t idx) const;
public:
    AutoPtr(Data *ptr = nullptr);

    explicit AutoPtr(size_t size);

    AutoPtr(const AutoPtr &obj) = delete;

    AutoPtr(AutoPtr &&obj);

    ~AutoPtr();

    size_t size() const;

    Data& operator*() const;

    Data* operator->() const;

    Data& operator[](size_t idx);

    const Data& operator[](size_t idx) const;

    AutoPtr& operator=(AutoPtr &&obj);

    operator bool() const;
};

#include "TestLib.tpp"

#endif
