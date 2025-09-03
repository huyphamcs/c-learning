#ifndef STACK_H
#define STACK_H

#include "IStack.h"
#include "ISLinkedList.h"

template <class T>
class Stack : public IStack<T>
{
public:
    Stack();
    Stack(T data);
    virtual ~Stack() = default;

    virtual void push(T data) override;
    virtual void pop() override;
    virtual T peek() override;
    virtual void print() override;
    virtual int getSize() override;
    virtual bool isEmpty() override;
    virtual void clear() override;
    virtual IStack<T>* clone() override;
};

// Template implementation for Stack constructors
template <class T>
Stack<T>::Stack() : IStack<T>() {}

template <class T>
Stack<T>::Stack(T data) : IStack<T>()
{
    this->top = new Node<T>(data);
    this->count = 1;
}

#endif
