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
    clear();
}



template<typename _list_elem_type>
void DoublyLinkedList<_list_elem_type>::push_back(const value_type& elem) noexcept
{
    if (m_list_head == nullptr) {
        m_list_head = new DoublyLinkedListNode(elem, nullptr, nullptr);
    }
    else {
        DoublyLinkedListNode* list_node {m_list_head};
        while (list_node->m_next != nullptr) {
            list_node = list_node->m_next;
        }
        list_node->m_next = new DoublyLinkedListNode(elem, list_node);
    }
    m_list_size++;
}



template<typename _list_elem_type>
void DoublyLinkedList<_list_elem_type>::push_front(const value_type& elem) noexcept
{
    m_list_head = new DoublyLinkedListNode(elem, nullptr, m_list_head);
    m_list_size++;
}



template<typename _list_elem_type>
void DoublyLinkedList<_list_elem_type>::pop_back() noexcept
{
    DoublyLinkedListNode* list_node {m_list_head};

    while (list_node->m_next->m_next != nullptr) {
        list_node = list_node->m_next;
    }

    delete list_node->m_next;
    list_node->m_next = nullptr;

    m_list_size--;
}



template<typename _list_elem_type>
void DoublyLinkedList<_list_elem_type>::pop_front() noexcept
{
    DoublyLinkedListNode* to_delete {m_list_head};
    m_list_head = m_list_head->m_next;
    delete to_delete;
    m_list_size--;
}



template<typename _list_elem_type>
void DoublyLinkedList<_list_elem_type>::clear() noexcept
{
    if (m_list_head != nullptr) {
        while (m_list_size != 0) {
            pop_front();
        }
    }
}



template<typename _list_elem_type>
void DoublyLinkedList<_list_elem_type>::remove_at(const size_type index)
{
    if (index >= m_list_size) {
        std::__throw_out_of_range_fmt("%s: Index '%zu' out of range!", __PRETTY_FUNCTION__, index);
    }

    if (index == 0) {
        pop_front();
    }
    else if (index == (m_list_size - 1)) {
        pop_back();
    }
    else {
        DoublyLinkedListNode* current_list_node {m_list_head};

        for (size_type i = 0; i < index - 1; i++) {
            current_list_node = current_list_node->m_next;
        }

        DoublyLinkedListNode* to_delete {current_list_node->m_next};
        DoublyLinkedListNode* next_node {to_delete->m_next};

        current_list_node->m_next = next_node;

        if (next_node != nullptr) {
            next_node->m_prev = current_list_node;
        }

        delete to_delete;
        m_list_size--;
    }
}



template<typename _list_elem_type>
void DoublyLinkedList<_list_elem_type>::insert_after(const value_type& elem, const size_type index)
{
    if (index >= m_list_size) {
        std::__throw_out_of_range_fmt("%s: Index '%zu' out of range!", __PRETTY_FUNCTION__, index);
    }

    if (index == 0) {
        push_front(elem);
    }
    else if (index == (m_list_size - 1)) {
        push_back(elem);
    }
    else {
        DoublyLinkedListNode* current_list_node {m_list_head};

        for (size_type i = 0; i < index - 1 ; i++) {
            current_list_node = current_list_node->m_next;
        }

        DoublyLinkedListNode* next_node {current_list_node->m_next};
        current_list_node->m_next = new DoublyLinkedListNode(elem, current_list_node, next_node);

        if (next_node != nullptr) {
            next_node->m_prev = current_list_node->m_next;
        }

        m_list_size++;
    }
}



template<typename _list_elem_type>
    typename DoublyLinkedList<_list_elem_type>::reference
DoublyLinkedList<_list_elem_type>::operator[](const size_type index) noexcept
{
    DoublyLinkedListNode* list_node {m_list_head};
    for (size_type i = 0; i < index; i++) {
        list_node = list_node->m_next;
    }
    return std::ref(list_node->m_data);
}



template<typename _list_elem_type>
    typename DoublyLinkedList<_list_elem_type>::const_reference
DoublyLinkedList<_list_elem_type>::operator[](const size_type index) const noexcept
{
    DoublyLinkedListNode* list_node {m_list_head};
    for (size_type i = 0; i < index; i++) {
        list_node = list_node->m_next;
    }
    return std::cref(list_node->m_data);
}



template<typename _list_elem_type>
    typename DoublyLinkedList<_list_elem_type>::reference
DoublyLinkedList<_list_elem_type>::at(const size_type index)
{
    if (index >= m_list_size) {
        std::__throw_out_of_range_fmt("%s: Index '%zu' out of range!", __PRETTY_FUNCTION__, index);
    }
}



template<typename _list_elem_type>
    typename DoublyLinkedList<_list_elem_type>::const_reference
DoublyLinkedList<_list_elem_type>::at(const size_type index) const
{
    if (index >= m_list_size) {
        std::__throw_out_of_range_fmt("%s: Index '%zu' out of range!", __PRETTY_FUNCTION__, index);
    }
}

} // namespace alex

#endif // DOUBLY_LINKED_LIST_IMPL_HPP