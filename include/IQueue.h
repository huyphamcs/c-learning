#include "INode.h"

template <class T>
class IQueue
{
public:
    INode<T> *front;
    int count;
    INode<T> *rear;
    IQueue();
    ~IQueue();
    // Push new data to the queue
    virtual void enQueue(T data) = 0;
    // Remove data from the queue
    virtual void deQueue() = 0;
    virtual T getFront() = 0;
    virtual T getRear() = 0;
    virtual void clear() = 0;
    virtual bool isEmpty() = 0;
    virtual int getSize() = 0;
    virtual void print() = 0;
};

template <class T>
IQueue<T>::IQueue()
{
    count = 0;
    front = nullptr;
    rear = nullptr;
}
template <class T>
IQueue<T>::~IQueue()
{

}