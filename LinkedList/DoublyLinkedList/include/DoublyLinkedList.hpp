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

private:
    DoublyLinkedListNode* m_list_head;
    size_type m_list_size;
};

} // namespace alex

#include "details/DoublyLinkedListImpl.hpp"

#endif // DOUBLY_LINKED_LIST_HPP