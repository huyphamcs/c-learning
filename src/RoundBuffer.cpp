#include <iostream>
#include <stdexcept>

// Constructor
template<class T>
RoundBuffer<T>::RoundBuffer(int capacity) {
    this->capacity = capacity;
    this->storage = new T[capacity];
    this->count = 0;
    this->front = 0;
    this->rear = 0;
}

// Destructor
template<class T>
RoundBuffer<T>::~RoundBuffer() {
    delete[] storage;
}

// Ensure capacity before adding new element
template<class T>
void RoundBuffer<T>::ensureCapacity() {
    if (count >= capacity) {
        throw std::overflow_error("RoundBuffer overflow: Cannot add more elements");
    }
}

// Add element to the buffer
template<class T>
void RoundBuffer<T>::push(T data) {
    ensureCapacity();
    storage[rear] = data;
    rear = (rear + 1) % capacity;
    count++;
}

// Remove and return element from the buffer
template<class T>
T RoundBuffer<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("RoundBuffer underflow: Cannot pop from empty buffer");
    }
    T output = storage[front];
    front = (front + 1) % capacity;
    count--;
    return output;
}

// Check if buffer is empty
template<class T>
bool RoundBuffer<T>::isEmpty() const {
    return count == 0;
}

// Check if buffer is full
template<class T>
bool RoundBuffer<T>::isFull() const {
    return count == capacity;
}

// Get current number of elements
template<class T>
int RoundBuffer<T>::getSize() const {
    return count;
}

// Get buffer capacity
template<class T>
int RoundBuffer<T>::getCapacity() const {
    return capacity;
}

// Clear all elements from buffer
template<class T>
void RoundBuffer<T>::clear() {
    front = 0;
    rear = 0;
    count = 0;
}

// Print buffer contents
template<class T>
void RoundBuffer<T>::print() const {
    if (isEmpty()) {
        std::cout << "Buffer is empty" << std::endl;
        return;
    }
    
    std::cout << "Buffer contents (front to rear): ";
    int current = front;
    for (int i = 0; i < count; i++) {
        std::cout << storage[current] << " ";
        current = (current + 1) % capacity;
    }
    std::cout << std::endl;
    std::cout << "Size: " << count << "/" << capacity << std::endl;
}
