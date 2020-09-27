#include <bits/c++config.h>
#include <bits/stl_iterator.h>
#include <bits/refwrap.h>

#ifndef LINKEDLISTITERATORS_HPP
#define LINKEDLISTITERATORS_HPP

namespace alex
{
namespace __detail
{
namespace __linked_list
{

template<typename _iterator_ty>
class LinkedListIterator
{
public:
    using value_type            = _iterator_ty;
    using difference_type       = std::ptrdiff_t;
    using pointer               = value_type*;
    using reference             = value_type&;
    using const_reference       = const value_type&;
    using iterator_category     = std::input_iterator_tag;

    explicit LinkedListIterator() noexcept
        : m_list_list_node {nullptr}
    {}
    
    explicit LinkedListIterator(LinkedListNode<value_type>* list_list_node) noexcept
        : m_list_list_node {list_list_node}
    {}

    explicit LinkedListIterator(const LinkedListIterator& other) noexcept
        : m_list_list_node {other.m_list_list_node}
    {}

    LinkedListIterator& operator=(const LinkedListIterator& other) noexcept
    {
        m_list_list_node = other.m_list_list_node;
        return *this;
    }

    LinkedListIterator& operator++() noexcept
    {
        m_list_list_node = m_list_list_node->m_next;
        return *this;
    }

    inline LinkedListIterator operator++(int) const noexcept
    { return LinkedListIterator(m_list_list_node->m_next); }

    LinkedListIterator operator+(std::size_t offset) noexcept
    {
        for (std::size_t i = 0; i < offset; i++) {
            m_list_list_node = m_list_list_node->m_next;
        }
        return LinkedListIterator(m_list_list_node);
    }

    inline bool operator==(const LinkedListIterator& other) noexcept
    { return m_list_list_node == other.m_list_list_node; }

    inline bool operator!=(const LinkedListIterator& other) noexcept
    { return m_list_list_node != other.m_list_list_node; }

    inline reference operator*() noexcept
    { return std::ref(m_list_list_node->m_data); }

private:
    LinkedListNode<value_type>* m_list_list_node;
};



template<typename _const_iterator_ty>
class ConstLinkedListIterator
{
public:
    using value_type            = _const_iterator_ty;
    using difference_type       = std::ptrdiff_t;
    using pointer               = value_type*;
    using reference             = value_type&;
    using const_reference       = const value_type&;
    using iterator_category     = std::input_iterator_tag;

    explicit ConstLinkedListIterator() noexcept
        : m_list_list_node {nullptr}
    {}
    
    explicit ConstLinkedListIterator(LinkedListNode<value_type>* list_list_node) noexcept
        : m_list_list_node {list_list_node}
    {}

    explicit ConstLinkedListIterator(const ConstLinkedListIterator& other) noexcept
        : m_list_list_node {other.m_list_list_node}
    {}

    ConstLinkedListIterator& operator=(const ConstLinkedListIterator& other) noexcept
    {
        m_list_list_node = other.m_list_list_node;
        return *this;
    }

    ConstLinkedListIterator& operator++() noexcept
    {
        m_list_list_node = m_list_list_node->m_next;
        return *this;
    }

    inline ConstLinkedListIterator operator++(int) const noexcept
    { return ConstLinkedListIterator(m_list_list_node->m_next); }

    ConstLinkedListIterator operator+(std::size_t offset) noexcept
    {
        for (std::size_t i = 0; i < offset; i++) {
            m_list_list_node = m_list_list_node->m_next;
        }
        return ConstLinkedListIterator(m_list_list_node);
    }

    inline bool operator==(const ConstLinkedListIterator& other) noexcept
    { return m_list_list_node == other.m_list_list_node; }

    inline bool operator!=(const ConstLinkedListIterator& other) noexcept
    { return m_list_list_node != other.m_list_list_node; }

    inline const_reference operator*() const noexcept
    { return std::cref(m_list_list_node->m_data); }

private:
    LinkedListNode<value_type>* m_list_list_node;
};

} // namespace __linked_list
} // namespace __detail
} // namespace alex

#endif // LINKEDLISTITERATORS_HPP
