#ifndef LINKEDLISTNODE_HPP
#define LINKEDLISTNODE_HPP

namespace alex
{
namespace __detail
{
namespace __linked_list
{

template<typename _node_elem_ty>
struct LinkedListNode
{
    LinkedListNode(const _node_elem_ty& data, LinkedListNode* next = nullptr) noexcept
        : m_data {data}
        , m_next {next}
    {}

    _node_elem_ty m_data;
    LinkedListNode* m_next;
};

} // namespace __linked_list
} // namespace __details
} // namespace alex

#endif // LINKEDLISTNODE_HPP
