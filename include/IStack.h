#ifndef ISTACK_H
#define ISTACK_H

#include "INode.h"

template <class T>
class IStack
{
protected:
    INode<T>* top;
    int count;

public:
    IStack();
    virtual ~IStack() = default;

    // Pure virtual functions that must be implemented
    virtual void push(T data) = 0;
    virtual void pop() = 0;
    virtual T peek() = 0;
    virtual void print() = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual void clear() = 0;
    virtual IStack<T>* clone() = 0;
};

// Template implementation for IStack constructor
template <class T>
IStack<T>::IStack()
{
    top = nullptr;
    count = 0;
}

#endif
