#ifndef NODE
#define NODE

template <class T>
class INode
{
public:
    T data;
    INode<T> *next;

public:
    INode();
    INode(T data);
    virtual ~INode() = default;
};

// Template implementations must be in header file
template <class T>
INode<T>::INode()
{
    this->next = nullptr;
}

template <class T>
INode<T>::INode(T data)
{
    this->data = data;
    this->next = nullptr;
}

#endif