#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>

#include "utils.tpp"

// Iterable - контейнер
// Iterator - итератор

template <typename Iterable>
auto enumerate(Iterable &&iterable) {
    using Iterator = decltype(std::begin(std::declval<Iterable>()));
    using T = decltype(*std::declval<Iterator>());

    class Enumerator {
    private:
        Iterator m_iterator;
        size_t m_idx;

    public:
        Enumerator(const Iterator &iterator, size_t idx=0) : m_iterator(iterator), m_idx(idx) {}

        bool operator!=(const Enumerator &other) const {
            return m_iterator != other.m_iterator;
        }

        std::pair<size_t, T> operator*() const {
            return {m_idx, *m_iterator};
        }

        Enumerator& operator++() {
            ++m_iterator;
            ++m_idx;
            return *this;
        }
    };

    struct Wrapper {
        Iterable &iterable;

        auto begin() const {
            return Enumerator(std::begin(iterable));
        }

        auto end() const {
            return Enumerator(std::end(iterable));
        }
    };

    return Wrapper {std::forward<Iterable>(iterable)};
}

auto range(size_t start, size_t end, size_t step=1) {
    std::vector<size_t> v_range;
    for (size_t i = start; i < end; i += step) {
        v_range.push_back(i);
    }

    return v_range;
}

auto range(size_t end) {
    return range(0, end);
}

#endif // UTILS_HPP
