#include <bits/stl_iterator.h>
#include <bits/refwrap.h>

#ifndef DOUBLY_LINKED_LIST_ITERATOR_HPP
#define DOUBLY_LINKED_LIST_ITERATOR_HPP

namespace alex
{
namespace __detail
{
namespace __doubly_linked_list
{

template<typename _iterator_type>
class DoublyLinkedListIterator
{
public:
    using value_type            = _iterator_type;
    using difference_type       = std::ptrdiff_t;
    using pointer               = value_type*;
    using reference             = value_type&;
    using iterator_category     = std::bidirectional_iterator_tag;

    DoublyLinkedListIterator() noexcept
        : m_list_node {nullptr}
    {}

    DoublyLinkedListIterator(DoublyLinkedListNode<value_type>* list_node) noexcept
        : m_list_node {list_node}
    {}

    DoublyLinkedListIterator(const DoublyLinkedListIterator& other) noexcept
        : m_list_node {other.m_list_node}
    {}

    DoublyLinkedListIterator& operator=(const DoublyLinkedListIterator& other) noexcept
    {
        m_list_node = other.m_list_node;
        return *this;
    }

    DoublyLinkedListIterator& operator++() noexcept
    {
        m_list_node = m_list_node->m_next;
        return *this;
    }

    inline DoublyLinkedListIterator operator++(int) noexcept
    { return DoublyLinkedListIterator(m_list_node->m_next); }

    DoublyLinkedListIterator operator+(std::size_t offset) noexcept
    {
        for (std::size_t i = 0; i < offset; i++) {
            m_list_node = m_list_node->m_next;
        }
        return DoublyLinkedListIterator(m_list_node);
    }

    DoublyLinkedListIterator& operator--() noexcept
    {
        m_list_node = m_list_node->m_prev;
        return *this;
    }

    inline DoublyLinkedListIterator operator--(int) noexcept
    { return DoublyLinkedListIterator(m_list_node->m_prev); }

    DoublyLinkedListIterator operator-(std::size_t offset) noexcept
    {
        for (std::size_t i = offset; i > 0; i--) {
            m_list_node = m_list_node->m_prev;
        }
        return DoublyLinkedListIterator(m_list_node);
    }

    inline bool operator==(const DoublyLinkedListIterator& other) const noexcept
    { return (m_list_node == other.m_list_node); }

    inline bool operator!=(const DoublyLinkedListIterator& other) const noexcept
    { return (m_list_node != other.m_list_node); }

    inline reference operator*() const noexcept
    { return std::ref(m_list_node->m_data); }

private:
    DoublyLinkedListNode<value_type>* m_list_node;
};



template<typename _const_iterator_type>
class DoublyLinkedListConstIterator
{
public:
    using value_type            = _const_iterator_type;
    using difference_type       = std::ptrdiff_t;
    using pointer               = value_type*;
    using reference             = value_type&;
    using const_reference       = const value_type&;
    using iterator_category     = std::bidirectional_iterator_tag;

    DoublyLinkedListConstIterator() noexcept
        : m_list_node {nullptr}
    {}

    DoublyLinkedListConstIterator(DoublyLinkedListNode<value_type>* list_node) noexcept
        : m_list_node {list_node}
    {}

    DoublyLinkedListConstIterator(const DoublyLinkedListConstIterator& other) noexcept
        : m_list_node {other.m_list_node}
    {}

    DoublyLinkedListConstIterator& operator=(const DoublyLinkedListConstIterator& other) noexcept
    {
        m_list_node = other.m_list_node;
        return *this;
    }

    DoublyLinkedListConstIterator& operator++() noexcept
    {
        m_list_node = m_list_node->m_next;
        return *this;
    }

    inline DoublyLinkedListConstIterator operator++(int) noexcept
    { return DoublyLinkedListConstIterator(m_list_node->m_next); }

    DoublyLinkedListConstIterator operator+(std::size_t offset) noexcept
    {
        for (std::size_t i = 0; i < offset; i++) {
            m_list_node = m_list_node->m_next;
        }
        return DoublyLinkedListConstIterator(m_list_node);
    }

    DoublyLinkedListConstIterator& operator--() noexcept
    {
        m_list_node = m_list_node->m_prev;
        return *this;
    }

    inline DoublyLinkedListConstIterator operator--(int) noexcept
    { return DoublyLinkedListConstIterator(m_list_node->m_prev); }

    DoublyLinkedListConstIterator operator-(std::size_t offset) noexcept
    {
        for (std::size_t i = offset; i > 0; i--) {
            m_list_node = m_list_node->m_prev;
        }
        return DoublyLinkedListConstIterator(m_list_node);
    }

    inline bool operator==(const DoublyLinkedListConstIterator& other) const noexcept
    { return (m_list_node == other.m_list_node); }

    inline bool operator!=(const DoublyLinkedListConstIterator& other) const noexcept
    { return (m_list_node != other.m_list_node); }

    inline const_reference operator*() const noexcept
    { return std::cref(m_list_node->m_data); }

private:
    DoublyLinkedListNode<value_type>* m_list_node;
};

} // namespace __doubly_linked_list
} // namespace __detail
} // namespace alex

#endif // DOUBLY_LINKED_LIST_ITERATOR_HPP