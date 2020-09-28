#include <bits/c++config.h>
#include <bits/refwrap.h>

#ifndef STACK_HPP
#define STACK_HPP

namespace alex
{

template<typename _elem_type>
class Stack
{
public:
    using value_type        = _elem_type;
    using reference         = value_type&;
    using size_type         = std::size_t;

    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    Stack() noexcept;
    ~Stack() noexcept;

    inline size_type size() const noexcept
    { return m_stack_size; }

    inline bool is_empty() const noexcept
    { return m_stack_size == 0; }

    void push(const value_type& element) noexcept;
    void pop() noexcept;
    void clear() noexcept;

    inline reference top() const noexcept
    { return std::ref(m_stack_top->m_data); }

private:
    struct StackNode
    {
        explicit StackNode(const value_type& data, StackNode* next = nullptr)
            : m_data {data}
            , m_next {next}
        {}

        value_type m_data;
        StackNode* m_next;
    } *m_stack_top;
    size_type m_stack_size;
};

} // namespace alex
#include "details/StackImpl.hpp"

#endif // STACK_HPP