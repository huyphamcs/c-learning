#include "../include/Stack.h"
#include "../include/SLinkedList.h"
#include <iostream>

using namespace std;

// Stack method implementations
template <class T>
void Stack<T>::push(T data)
{
    Node<T>* newNode = new Node<T>(data);
    newNode->next = this->top;
    this->top = newNode;
    this->count++;
}

template <class T>
void Stack<T>::pop()
{
    if (isEmpty()) {
        throw runtime_error("Cannot pop from empty stack");
    }
    INode<T>* tempPtr = this->top;
    this->top = this->top->next;
    delete tempPtr;
    this->count--;
}

template <class T>
T Stack<T>::peek()
{
    if (isEmpty()) {
        throw runtime_error("Cannot peek empty stack");
    }
    return this->top->data;
}

template <class T>
void Stack<T>::print()
{
    INode<T>* tempPtr = this->top;
    cout << "Stack (top to bottom): ";
    while (tempPtr != nullptr)
    {
        cout << tempPtr->data << " ";
        tempPtr = tempPtr->next;
    }
    cout << endl;
}

template <class T>
int Stack<T>::getSize()
{
    return this->count;
}

template <class T>
bool Stack<T>::isEmpty()
{
    return (this->count == 0);
}

template <class T>
void Stack<T>::clear()
{
    SLinkedList<T>* tempList = new SLinkedList<T>();
    tempList->head = this->top;
    tempList->destroy();
    delete tempList;
    this->top = nullptr;
    this->count = 0;
}

template <class T>
IStack<T>* Stack<T>::clone()
{
    Stack<T>* newStack = new Stack<T>();
    
    if (this->top != nullptr) {
        // Use SLinkedList to help with cloning
        SLinkedList<T>* tempList = new SLinkedList<T>();
        tempList->head = this->top;
        
        ISLinkedList<T>* clonedList = tempList->clone();
        newStack->top = clonedList->head;
        newStack->count = this->count;
        
        // Clean up temporary objects (but don't destroy the data)
        tempList->head = nullptr; // Don't let it destroy our original data
        delete tempList;
        delete clonedList;
    }
    
    return newStack;
}

// Explicit template instantiations (add as needed)
template class Stack<int>;
template class Stack<double>;
template class Stack<string>;
