#include "IQueue.h"

#ifndef QUEUE
#define QUEUE

template<class T>
class Queue : public IQueue<T>{
public:
    Queue();
    virtual ~Queue();
    virtual void enQueue(T data) override;
    // Remove data from the queue and return that data
    virtual void deQueue() override;
    virtual T getFront() override;
    virtual T getRear() override;
    virtual void clear() override;
    virtual bool isEmpty() override;
    virtual int getSize() override;
    virtual void print() override;
};

// Template class implementations must be in header file
// #include "../src/Queue.cpp"

#endif