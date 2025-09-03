#include "INode.h"

#ifndef ISLINKED_LIST_H
#define ISLINKED_LIST_H



template <class T>
class ISLinkedList
{
public:
    int count;
    INode<T>* head;

public:
    ISLinkedList();
    virtual ~ISLinkedList() = default;

    // Pure virtual functions that must be implemented
    virtual void print() = 0;
    virtual int getSize() = 0;
    virtual void pushBack(T value) = 0;
    virtual void insertAt(int index, T value) = 0;
    virtual void deleteAt(int index) = 0;
    virtual void tranverse() = 0;
    virtual T findAtIndex(int index) = 0;
    virtual void destroy() = 0;
    // virtual ISLinkedList<T>* clone() = 0;
};

// Template implementation for ISLinkedList constructor
template <class T>
ISLinkedList<T>::ISLinkedList()
{
    count = 0;
    this->head = nullptr;
}

#endif