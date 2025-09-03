
#include "../include/SLinkedList.h"
#include <iostream>

using namespace std;

// SLinkedList method implementations
template <class T>
void SLinkedList<T>::print() {
    INode<T>* tempPtr = this->head;
    while(tempPtr != nullptr){
        cout << tempPtr->data << " ";
        tempPtr = tempPtr->next;
    }
    cout << endl;
}

template <class T>
int SLinkedList<T>::getSize() {
    INode<T>* tempPtr = this->head;
    int size = 0;
    while(tempPtr != nullptr) {
        tempPtr = tempPtr->next;
        size++;
    }
    return size;
}

template <class T>
void SLinkedList<T>::pushBack(T value){
    if (!getSize()) this->head = new Node<T>(value);
    else{
        INode<T>* temp = this->head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new Node<T>(value);
    }
}

template <class T>
void SLinkedList<T>::insertAt(int index, T value){
    if (index == 0){
        Node<T>* tempPtr = new Node<T>(value);
        tempPtr->next = this->head;
        this->head = tempPtr;
    }
    else if (index > 0 && index < getSize()){
        INode<T>* tempPtr = this->head;
        INode<T>* prePtr = nullptr;
        Node<T>* newNode = new Node<T>(value);
        for (int i = 0; i < index; i++){
            prePtr = tempPtr;
            tempPtr = tempPtr->next;
        }
        newNode->next = tempPtr;
        prePtr->next = newNode;
    }
    else if (index == getSize()){
        pushBack(value);
    }
}

template <class T>
void SLinkedList<T>::deleteAt(int index){
    if (!index){
        INode<T>* tempPtr = this->head;
        this->head = this->head->next;
        delete tempPtr;
    }
    else if (index > 0 && index < getSize()){
        INode<T>* tempPtr = this->head;
        INode<T>* prePtr = nullptr;
        for (int i = 0; i < index; i++){
            prePtr = tempPtr;
            tempPtr = tempPtr->next;
        }
        prePtr->next = tempPtr->next;
        delete tempPtr;
    }
} 

template <class T>
void SLinkedList<T>::tranverse() {
    SLinkedList<T>* newList = new SLinkedList<T>();
    INode<T>* tempPtr = this->head;
    Node<T>* newNode = new Node<T>(tempPtr->data);

    while (tempPtr->next != nullptr){
        Node<T>* newNode2 = new Node<T>(tempPtr->next->data);
        newNode2->next = newNode;
        newNode = newNode2;
        newList->head = newNode2;
        tempPtr = tempPtr->next;
    }
    this->head = newList->head;
    newList->destroy();
}

template <class T>
T SLinkedList<T>::findAtIndex(int index){
    if (index>=0 && index < getSize()){
        INode<T>* tempPtr = this->head;
        for (int i = 0; i < index; i++){
            tempPtr = tempPtr->next;
        }
        return tempPtr->data;
    }
    return T(); // Return default value instead of -1 for generic type
}

template <class T>
void SLinkedList<T>::destroy() {
    int size = getSize();
    for (int i = 0; i < size; i++){
        INode<T>* tempPtr = this->head;
        this->head = tempPtr->next;
        delete tempPtr;
    }
}

template <class T>
SLinkedList<T>* SLinkedList<T>::clone() {
    SLinkedList<T>* newList = new SLinkedList<T>();
    INode<T>* tempPtr = this->head;
    int size = getSize();
    Node<T>* newHead = new Node<T>(tempPtr->data);
    newList->head = newHead;
    tempPtr = tempPtr->next;
    INode<T>* newTemp = newHead;

    for (int i = 0; i < size-1; i++){
        Node<T>* newNode = new Node<T>(tempPtr->data);
        newTemp->next = newNode;
        newTemp = newTemp->next;
        tempPtr = tempPtr->next;
    }
    return newList;
}

// Explicit template instantiations (add as needed)
template class SLinkedList<int>;
template class SLinkedList<double>;
template class SLinkedList<string>;
template class Node<int>;
template class Node<double>;
template class Node<string>;