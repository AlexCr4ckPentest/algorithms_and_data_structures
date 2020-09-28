#include "details/DoubleLinkedListNode.hpp"
#include "details/DoubleLinkedListIterator.hpp"

#ifndef DOUBLE_LINKED_LIST_HPP
#define DOUBLE_LINKED_LIST_HPP

namespace alex
{

template<typename _list_elem_type>
class DoubleLinkedList
{
public:
    using value_type                = _list_elem_type;
    using size_type                 = std::size_t;

    using reference                 = value_type&;
    using const_reference           = const value_type&;

    using iterator                  = __detail::__double_linked_list::DoubleLinkedListIterator<value_type>;
    using const_iterator            = __detail::__double_linked_list::ConstDoubleLinkedListIterator<value_type>;
    using reverse_iterator          = std::reverse_iterator<iterator>;
    using const_reverse_iterator    = std::reverse_iterator<const_iterator>;

    using DoubleLinkedListNode      = __detail::__double_linked_list::DoubleLinkedListNode<value_type>;

    DoubleLinkedList() noexcept;
    ~DoubleLinkedList() noexcept;

private:
    DoubleLinkedListNode* m_list_head;
    size_type m_list_size;
};

} // namespace alex

#include "details/DoubleLinkedListImpl.hpp"

#endif // DOUBLE_LINKED_LIST_HPP