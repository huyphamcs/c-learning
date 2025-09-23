#include<iostream>
using namespace std;

class RoundBuffer{
public:
    int* storage;
    int front;
    int rear;
    int capacity;
    int count;
    RoundBuffer(int capacity = 10) {
        storage = new int[capacity];
        this->capacity = capacity;
        count = 0;
        front = 0;
        rear = 0;
    }
    void ensureCapacity() {
        if (count >= capacity) throw(overflow_error("Overflow"));
    }
    void push (int data){
        *(storage + rear) = data;
        rear = (rear+1)%capacity;
        count++;
    }
    int pop(){
        if (count==0) throw(underflow_error("Underflow"));
        int output = *(storage+front);
        front = (front+1)%capacity;
        count--;
        return output;
    }
    bool isEmpty(){
        return front == rear;
    }
    bool isFull() {
        return count == capacity;
    }
};

int main () {
    RoundBuffer* newBuffer = new RoundBuffer();
    for (int i = 0; i < 5; i++)newBuffer->push(i);
    for (int i = 0; i < 5; i++)cout << newBuffer->pop() << " ";

    for (int i = 0; i < 3; i++)newBuffer->push(i);
    for (int i = 0; i < 3; i++)cout << newBuffer->pop() << " ";
    return 0;
}