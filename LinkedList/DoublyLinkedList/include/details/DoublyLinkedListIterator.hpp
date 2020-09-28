#include <bits/stl_iterator.h>

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

private:
    DoublyLinkedListNode<value_type>* m_list_node;
};



template<typename _const_iterator_type>
class ConstDoublyLinkedListIterator
{
public:
    using value_type            = _const_iterator_type;
    using difference_type       = std::ptrdiff_t;
    using pointer               = value_type*;
    using reference             = value_type&;
    using iterator_category     = std::bidirectional_iterator_tag;

private:
    DoublyLinkedListNode<value_type>* m_list_node;
};

} // namespace __doubly_linked_list
} // namespace __detail
} // namespace alex

#endif // DOUBLY_LINKED_LIST_ITERATOR_HPP