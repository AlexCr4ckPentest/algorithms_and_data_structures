#include "details/LinkedListNode.hpp"
#include "details/LinkedListIterators.hpp"

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

namespace alex
{

/// ----------------------------------------------------------------------------------------
/// My own singly linked list implementation (with custom iterators)
/// ----------------------------------------------------------------------------------------
template<typename _list_elem_type>
class LinkedList
{
public:
    using value_type        = _list_elem_type;
    using size_type         = std::size_t;
    using difference_type   = std::ptrdiff_t;
    using pointer           = value_type*;
    using reference         = value_type&;
    using const_reference   = const value_type&;
    using iterator          = __detail::__linked_list::LinkedListIterator<value_type>;
    using const_iterator    = __detail::__linked_list::ConstLinkedListIterator<value_type>;

private:
    using LinkedListNode    = __detail::__linked_list::LinkedListNode<value_type>;

public:
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    LinkedList() noexcept;
    ~LinkedList() noexcept;

    void push_back(const value_type& data) noexcept;
    void push_front(const value_type& data) noexcept;
    void pop_back() noexcept;
    void pop_front() noexcept;
    void clear() noexcept;

    void insert(const value_type& data, const size_type pos) noexcept;
    void remove_at(const size_type index) noexcept;

    inline reference operator[](const size_type index) noexcept
    { return (std::ref(*(begin() + index))); }

    inline const_reference operator[](const size_type index) const noexcept
    { return (std::cref(*(cbegin() + index))); }

    reference at(const size_type index);
    const_reference at(const size_type index) const;

    inline iterator begin() noexcept
    { return iterator(m_list_head); }

    inline const_iterator cbegin() const noexcept
    { return const_iterator(m_list_head); }

    inline iterator end() noexcept
    { return iterator(begin() + m_list_size); }

    inline const_iterator cend() const noexcept
    { return const_iterator(cbegin() + m_list_size); }

    inline size_type size() const noexcept
    { return m_list_size; }

    inline bool is_empty() const noexcept
    { return m_list_size == 0; }

private:
    LinkedListNode* m_list_head;
    size_type m_list_size;
};

} // namespace alex

/// Include implementation
#include "details/LinkedListImpl.hpp"

#endif // LINKEDLIST_HPP
