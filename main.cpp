#include "include/INode.h"
#include "include/SLinkedList.h"
#include "include/Queue.h"
#include <iostream>
using namespace std;

int main(){
    Queue<int>* newQueue = new Queue<int>();
    newQueue->print();
    for (int i = 0; i < 10; i++) newQueue->enQueue(i);
    newQueue->print();
    newQueue->deQueue();
    newQueue->deQueue();

    newQueue->print();
    newQueue->clear();
    newQueue->print();
    
    delete newQueue;

    return 0;
}