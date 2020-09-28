#ifndef DOUBLE_LINKED_LIST_IMPL_HPP
#define DOUBLE_LINKED_LIST_IMPL_HPP

namespace alex
{

template<typename _list_elem_type>
DoubleLinkedList<_list_elem_type>::DoubleLinkedList() noexcept
    : m_list_head {nullptr}
    , m_list_size {0}
{}



template<typename _list_elem_type>
DoubleLinkedList<_list_elem_type>::~DoubleLinkedList() noexcept
{}

} // namespace alex

#endif // DOUBLE_LINKED_LIST_IMPL_HPP