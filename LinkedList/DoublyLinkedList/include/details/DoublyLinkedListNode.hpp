#ifndef DOUBLY_LINKED_LIST_NODE_HPP
#define DOUBLY_LINKED_LIST_NODE_HPP

namespace alex
{
namespace __detail
{
namespace __doubly_linked_list
{

template<typename _node_elem_type>
struct DoublyLinkedListNode
{
    explicit DoublyLinkedListNode(const _node_elem_type& data,
                                DoublyLinkedListNode* prev,
                                DoublyLinkedListNode* next = nullptr) noexcept
        : m_data {data}
        , m_prev {prev}
        , m_next {next}
    {}

    _node_elem_type m_data;
    DoublyLinkedListNode* m_prev;
    DoublyLinkedListNode* m_next;
};

} // namespace __doubly_linked_list
} // namespace __detail
} // namespace alex

#endif // DOUBLY_LINKED_LIST_NODE_HPP