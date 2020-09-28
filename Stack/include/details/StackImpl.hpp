#include "../Stack.hpp"

#ifndef STACKIMPL_HPP
#define STACKIMPL_HPP

namespace alex
{

template<typename _elem_type>
Stack<_elem_type>::Stack() noexcept
    : m_stack_top {nullptr}
    , m_stack_size {0}
{}



template<typename _elem_type>
Stack<_elem_type>::~Stack() noexcept
{
    if (m_stack_top != nullptr) {
        clear();
    }
}



template<typename _elem_type>
void Stack<_elem_type>::push(const value_type& element) noexcept
{
    m_stack_top = new StackNode(element, m_stack_top);
    m_stack_size++;
}



template<typename _elem_type>
void Stack<_elem_type>::pop() noexcept
{
    StackNode* to_delete {m_stack_top};

    m_stack_top = to_delete->m_next;
    delete to_delete;

    m_stack_size--;
}



template<typename _elem_type>
void Stack<_elem_type>::clear() noexcept
{
    while (m_stack_size != 0) {
        pop();
    }
}

} // namesapce alex

#endif // STACKIMPL_HPP