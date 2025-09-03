#include <iostream>
#include "src/SLinkedList.cpp"
#include <math.h>
using namespace std;

template <class T>
class Stack
{
    INode<T> *top;
    int count;

public:
    friend SLinkedList<T>;
    Stack()
    {
        top = nullptr;
        count = 0;
    }
    Stack(T data)
    {
        top = new Node<T>(data);
        count = 1;
    }
    void print()
    {
        INode<T> *tempPtr = top;
        cout << "Stack (top to bottom): ";
        while (tempPtr != nullptr)
        {
            cout << tempPtr->data << " ";
            tempPtr = tempPtr->next;
        }
        cout << endl;
    }
    void push(T data)
    {
        INode<T> *newNode = new INode<T>(data);
        newNode->next = top;
        top = newNode;
        count++;
        
    }
    void pop()
    {
        INode<T> *tempPtr = top;
        top = top->next;
        delete tempPtr;
        count--;
    }
    int getSize(){
        return count;
    }
    bool isEmpty(){
        return (count == 0);
    }
    void clear(){
        SLinkedList<T>* newList = new SLinkedList<T>();
        newList->head = top;
        newList->destroy();
        top = nullptr;
        count = 0;
    }
    void clone(){
        SLinkedList<T>* newList = new SLinkedList<T>();
        newList->head = top;
        newList = newList->clone();
        newList->tranverse();
        newList->print();
    }
};

int main()
{
    // Test the Stack
    Stack<int> *myStack = new Stack<int>();
    for (int i = 0; i < 10; i++)
    {
        myStack->push(i);
    }
    myStack->clone();
    myStack->print();
    return 0;
}