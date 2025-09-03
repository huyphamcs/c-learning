#ifndef SLINKED_LIST_H
#define SLINKED_LIST_H

#include "ISLinkedList.h"

template <class T>
class Node : public INode<T>
{
public:
    Node();
    Node(T data);
    virtual ~Node() = default;
};

template <class T>
class SLinkedList : public ISLinkedList<T>
{
public:
    SLinkedList();
    virtual ~SLinkedList() = default;

    virtual void print() override;
    virtual int getSize() override;
    virtual void pushBack(T value) override;
    virtual void insertAt(int index, T value) override;
    virtual void deleteAt(int index) override;
    virtual void tranverse() override;
    virtual T findAtIndex(int index) override;
    virtual void destroy() override;
    virtual SLinkedList<T>* clone() override;
};

// Template implementations for Node constructors
template <class T>
Node<T>::Node() : INode<T>() {}

template <class T>
Node<T>::Node(T data) : INode<T>(data) {}

// Template implementation for SLinkedList constructor
template <class T>
SLinkedList<T>::SLinkedList() : ISLinkedList<T>() {}

#endif
