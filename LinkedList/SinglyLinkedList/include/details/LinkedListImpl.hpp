#include "../LinkedList.hpp"

#ifndef LINKEDLISTIMPL_HPP
#define LINKEDLISTIMPL_HPP

namespace alex
{

template<typename _list_elem_type>
LinkedList<_list_elem_type>::LinkedList() noexcept
    : m_list_head {nullptr}
    , m_list_size {0}
{}



template<typename _ty>
LinkedList<_ty>::~LinkedList() noexcept
{
    if (m_list_head != nullptr) {
        while (m_list_size != 0) {
            pop_front();
        }
    }
}



template<typename _list_elem_type>
void LinkedList<_list_elem_type>::push_back(const value_type& data) noexcept
{
    if (m_list_head == nullptr) {
        m_list_head = new LinkedListNode(data);
    }
    else {
        LinkedListNode* list_node = m_list_head;

        while (list_node->m_next != nullptr) {
            list_node = list_node->m_next;
        }

        list_node->m_next = new LinkedListNode(data);
    }
    m_list_size++;
}



template<typename _list_elem_type>
void LinkedList<_list_elem_type>::push_front(const value_type& data) noexcept
{
    m_list_head = new LinkedListNode(data, m_list_head);
    m_list_size++;
}



template<typename _list_elem_type>
void LinkedList<_list_elem_type>::pop_back() noexcept
{
    LinkedListNode* list_node {m_list_head};

    while (list_node->m_next->m_next != nullptr) {
        list_node = list_node->m_next;
    }

    delete list_node->m_next;
    list_node->m_next = nullptr;

    m_list_size--;
}



template<typename _list_elem_type>
void LinkedList<_list_elem_type>::pop_front() noexcept
{
    LinkedListNode* list_node {m_list_head};

    m_list_head = list_node->m_next;

    delete list_node;
    m_list_size--;
}



template<typename _list_elem_type>
void LinkedList<_list_elem_type>::clear() noexcept
{
    while (m_list_size != 0) {
        pop_front();
    }
}



template<typename _list_elem_type>
void LinkedList<_list_elem_type>::insert(const value_type& data, const size_type pos) noexcept
{
    if (pos == 0) {
        push_front(data);
    }
    else if (pos == (m_list_size - 1)) {
        push_back(data);
    }
    else {
        LinkedListNode* list_node {m_list_head};

        for (size_type i = 0; i < pos - 1; i++) {
            list_node = list_node->m_next;
        }

        list_node->m_next = new LinkedListNode(data, list_node->m_next);
    }
}



template<typename _list_elem_type>
void LinkedList<_list_elem_type>::remove_at(const size_type index) noexcept
{
    if (index == 0) {
        pop_front();
    }
    else if (index == (m_list_size - 1)) {
        pop_back();
    }
    else {
        LinkedListNode* list_node {m_list_head};
        LinkedListNode* node_to_remove {nullptr};

        for (size_type i = 0; i < index - 1; i ++) {
            list_node = list_node->m_next;
        }

        node_to_remove = list_node->m_next;
        list_node->m_next = node_to_remove->m_next;

        delete node_to_remove;
        m_list_size--;
    }
}


template<typename _list_elem_type>
    typename LinkedList<_list_elem_type>::reference
LinkedList<_list_elem_type>::at(const size_type index)
{
    if (index >= m_list_size) {
        std::__throw_out_of_range_fmt("%s: Index '%zu' out of range!", __PRETTY_FUNCTION__, index);
    }
    return (std::ref(*(begin() + index)));
}



template<typename _list_elem_type>
    typename LinkedList<_list_elem_type>::const_reference
LinkedList<_list_elem_type>::at(const size_type index) const
{
    if (index >= m_list_size) {
        std::__throw_out_of_range_fmt("%s: Index '%zu' out of range!", __PRETTY_FUNCTION__, index);
    }
    return (std::cref(*(cbegin() + index)));
}

} // namespace alex

#endif // LINKEDLISTIMPL_HPP
