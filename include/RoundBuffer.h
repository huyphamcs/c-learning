#ifndef ROUNDBUFFER_H
#define ROUNDBUFFER_H

#include <stdexcept>

template<class T>
class RoundBuffer {
private:
    T* storage;
    int front;
    int rear;
    int capacity;
    int count;

public:
    // Constructor
    RoundBuffer(int capacity = 10);
    
    // Destructor
    ~RoundBuffer();
    
    // Core operations
    void push(T data);
    T pop();
    
    // Utility methods
    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;
    int getCapacity() const;
    void clear();
    
    // Display method
    void print() const;

private:
    void ensureCapacity();
};

// Template class implementations must be in header file
#include "../src/RoundBuffer.cpp"

#endif
