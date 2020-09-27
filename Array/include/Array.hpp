#include <bits/c++config.h>
#include <bits/refwrap.h>
#include <bits/stl_iterator.h>

#ifndef ARRAY_HPP
#define ARRAY_HPP

namespace alex
{

/// ----------------------------------------------------------------------------------------
/// My own C++array implementation (with iterators)
/// ----------------------------------------------------------------------------------------
template<typename _array_ty, std::size_t _size>
class Array
{
public:
    using value_type                = _array_ty;
    using size_type                 = std::size_t;
    using difference_type           = std::ptrdiff_t;
    using pointer                   = value_type*;
    using const_pointer             = const value_type*;
    using reference                 = value_type&;
    using const_reference           = const value_type&;
    using iterator                  = value_type*;
    using const_iterator            = const value_type*;
    using reverse_iterator          = std::reverse_iterator<iterator>;
    using const_reverse_iterator    = std::reverse_iterator<const_iterator>;

    constexpr Array() noexcept
        : m_actual_data {0}
    {}

    inline constexpr size_type size() const noexcept
    { return _size; }

    inline constexpr bool is_empty() const noexcept
    { return _size == 0; }

    inline constexpr pointer actual_data() noexcept
    { return m_actual_data; }

    inline constexpr const_pointer actual_data() const noexcept
    { return m_actual_data; }

    inline void fill(const value_type& values) noexcept
    { std::fill(begin(), end(), values); }

    inline void fill_n(const value_type& values, const size_type range) noexcept
    { std::fill_n(begin(), range, values); }

    inline void swap(Array& other) noexcept
    { std::swap_ranges(begin(), end(), other.begin()); }

    inline void reverse() noexcept
    { std::reverse(begin(), end()); }



    inline constexpr iterator begin() noexcept
    { return iterator(m_actual_data); }

    inline constexpr const_iterator begin() const noexcept
    { return const_iterator(m_actual_data); }

    inline constexpr iterator end() noexcept
    { return iterator(m_actual_data + _size); }

    inline constexpr const_iterator end() const noexcept
    { return const_iterator(m_actual_data + _size); }

    inline constexpr reverse_iterator rbegin() noexcept
    { return reverse_iterator(end()); }

    inline constexpr const_reverse_iterator rbegin() const noexcept
    { return const_reverse_iterator(end()); }

    inline constexpr reverse_iterator rend() noexcept
    { return reverse_iterator(begin()); }

    inline constexpr const_reverse_iterator rend() const noexcept
    { return const_reverse_iterator(begin()); }

    inline constexpr const_iterator cbegin() const noexcept
    { return const_iterator(begin()); }

    inline constexpr const_iterator cend() const noexcept
    { return const_iterator(end()); }

    inline constexpr const_reverse_iterator crbegin() const noexcept
    { return const_reverse_iterator(cend()); }

    inline constexpr const_reverse_iterator crend() const noexcept
    { return const_reverse_iterator(cbegin()); }


    inline constexpr reference first() noexcept
    { return std::ref(*m_actual_data); }

    inline constexpr const_reference first() const noexcept
    { return std::cref(*m_actual_data); }

    inline constexpr reference last() noexcept
    { return std::ref(m_actual_data[_size - 1]); }

    inline constexpr const_reference last() const noexcept
    { return std::cref(m_actual_data[_size - 1]); }



    inline constexpr reference operator[](const size_type index) noexcept
    { return std::ref(m_actual_data[index]); }

    inline constexpr const_reference operator[](const size_type index) const noexcept
    { return std::cref(m_actual_data[index]); }

    constexpr reference at(const size_type index) noexcept
    {
        if (index >= _size) {
            std::__throw_out_of_range_fmt("Array::at: Index %zu out of range!", index);
        }
        return std::ref(m_actual_data[index]);
    }

    constexpr const_reference at(const size_type index) const noexcept
    {
        if (index >= _size) {
            std::__throw_out_of_range_fmt("Array::at: Index %zu out of range!", index);
        }
        return std::cref(m_actual_data[index]);
    }



    inline constexpr bool operator==(const Array& other) const noexcept
    { return std::equal(cbegin(), cend(), other.cbegin()); }

    inline constexpr bool operator!=(const Array& other) const noexcept
    { return *this == other; }

    inline constexpr bool operator<(const Array& other) const noexcept
    { return std::lexicographical_compare(cbegin(), cend(), other.cbegin(). other.cend()); }

    inline constexpr bool operator>(const Array& other) const noexcept
    { return *this < other; }

    inline constexpr bool operator<=(const Array& other) const noexcept
    { return !(*this > other); }

    inline constexpr bool operator>=(const Array& other) const noexcept
    { return !(*this < other); }

private:
    value_type m_actual_data[_size];
};

} // namespace alex

#endif // ARRAY_HPP
