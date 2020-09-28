#include "../DoublyLinkedList.hpp"

#ifndef DOUBLY_LINKED_LIST_IMPL_HPP
#define DOUBLY_LINKED_LIST_IMPL_HPP

namespace alex
{

template<typename _list_elem_type>
DoublyLinkedList<_list_elem_type>::DoublyLinkedList() noexcept
    : m_list_head {nullptr}
    , m_list_size {0}
{}



template<typename _list_elem_type>
DoublyLinkedList<_list_elem_type>::~DoublyLinkedList() noexcept
{
    if (m_list_head != nullptr) {}
}

}

#endif // DOUBLY_LINKED_LIST_IMPL_HPP