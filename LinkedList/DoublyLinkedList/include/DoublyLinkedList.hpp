#include "details/DoublyLinkedListNode.hpp"
#include "details/DoublyLinkedListIterator.hpp"

#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

namespace alex
{

template<typename _list_elem_type>
class DoublyLinkedList
{
public:
    using value_type                = _list_elem_type;
    using size_type                 = std::size_t;

    using reference                 = value_type&;
    using const_reference           = const value_type&;

    using iterator                  = __detail::__doubly_linked_list::DoublyLinkedListIterator<value_type>;
    using const_iterator            = __detail::__doubly_linked_list::ConstDoublyLinkedListIterator<value_type>;
    using reverse_iterator          = std::reverse_iterator<iterator>;
    using const_reverse_iterator    = std::reverse_iterator<const_iterator>;

    using DoublyLinkedListNode      = __detail::__doubly_linked_list::DoublyLinkedListNode<value_type>;

    DoublyLinkedList() noexcept;
    ~DoublyLinkedList() noexcept;

    void push_back(const value_type& elem) noexcept;
    void push_front(const value_type& elem) noexcept;
    void pop_back() noexcept;
    void pop_front() noexcept;
    void clear() noexcept;
    void remove_at(const size_type index);
    void insert_after(const value_type& elem, const size_type index);

    inline size_type size() const noexcept
    { return m_list_size; }

    inline bool is_empty() const noexcept
    { return m_list_size == 0; }

    reference operator[](const size_type index) noexcept;
    const_reference operator[](const size_type index) const noexcept;

private:
    DoublyLinkedListNode* m_list_head;
    size_type m_list_size;
};

} // namespace alex

#include "details/DoublyLinkedListImpl.hpp"

#endif // DOUBLY_LINKED_LIST_HPP