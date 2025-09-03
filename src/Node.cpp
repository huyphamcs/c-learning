#include "../include/INode.h"

template <class T>
class Node : public INode<T>
{
public:
    Node() : INode<T>() {}
    Node(T data) : INode<T>(data) {}
    virtual ~Node() = default;
};