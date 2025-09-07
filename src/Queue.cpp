#include "../include/INode.h"
#include <iostream>
using namespace std;

template<class T>
Queue<T>::Queue() : IQueue<T>() {
    // Constructor is already implemented in IQueue
}

template<class T>
Queue<T>::~Queue() {
    clear();
}

template<class T>
void Queue<T>::enQueue(T data) {
    INode<T>* newNode = new INode<T>(data);
    if (!this->count) {
        this->front = newNode;
        this->rear = newNode;
    }
    else {
        newNode->next = this->front;
        this->front = newNode;
    }
    this->count++;
}

template<class T>
void Queue<T>::deQueue() {
    if (this->count == 0) return;
    
    if (this->count == 1) {
        delete this->front;
        this->front = nullptr;
        this->rear = nullptr;
        this->count = 0;
        return;
    }
    
    INode<T>* newNode = this->front;
    for (int i = 0; i < this->count - 2; i++) {
        newNode = newNode->next;
    }
    this->rear = newNode;
    newNode = newNode->next;
    this->count--;
    delete newNode;
}

template<class T>
T Queue<T>::getFront() {
    return this->front->data;
}

template<class T>
T Queue<T>::getRear() {
    return this->rear->data;
}

template<class T>
bool Queue<T>::isEmpty() {
    return !this->count;
}

template<class T>
int Queue<T>::getSize() {
    return this->count;
}

template<class T>
void Queue<T>::print() {
    if (!this->count) {
        cout << "Empty queue" << endl;
        return;
    }
    INode<T>* temp = this->front;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != this->rear);
    cout << this->rear->data << " ";
    cout << endl;
}

template<class T>
void Queue<T>::clear() {
    if (this->count == 0) return;
    
    if (this->count == 1) {
        delete this->front;
        this->front = nullptr;
        this->rear = nullptr;
        this->count = 0;
        return;
    }
    
    do {
        INode<T>* temp = this->front;
        this->front = this->front->next;
        delete temp;
    } while (this->front != this->rear);
    
    delete this->rear;
    this->front = nullptr;
    this->rear = nullptr;
    this->count = 0;
}
