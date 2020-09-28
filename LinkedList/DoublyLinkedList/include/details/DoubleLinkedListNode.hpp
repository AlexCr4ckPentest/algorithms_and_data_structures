#ifndef DOUBLE_LINKED_LIST_NODE_HPP
#define DOUBLE_LINKED_LIST_NODE_HPP

namespace alex
{
namespace __detail
{
namespace __double_linked_list
{

template<typename _node_elem_type>
struct DoubleLinkedListNode
{
    explicit DoubleLinkedListNode(const _node_elem_type& data,
                                DoubleLinkedListNode* prev,
                                DoubleLinkedListNode* next = nullptr) noexcept
        : m_data {data}
        , m_prev {prev}
        , m_prev {next}
    {}

    _node_elem_type m_data;
    DoubleLinkedListNode* m_prev;
    DoubleLinkedListNode* m_next;
};

} // namespace __double_linked_list
} // namespace __detail
} // namespace alex

#endif // DOUBLE_LINKED_LIST_NODE_HPP