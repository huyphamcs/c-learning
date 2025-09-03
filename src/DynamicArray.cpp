#include "../include/IDynamicArray.h"
#include <iostream>
#include <cstring>

using namespace std;

class DynamicArray : public IDynamicArray
{
public:
    DynamicArray() : IDynamicArray() {}

    DynamicArray(int capacity) : IDynamicArray(capacity) {}

    virtual ~DynamicArray() {}

    virtual void setCapacity(int) override;
    virtual void ensureCapacity(int) override;
    virtual void pack() override;
    virtual void trim() override;
    virtual void rangeCheck(int) override;
    virtual void set(int, int) override;
    virtual int get(int) override;
    virtual void removeAt(int) override;
    virtual void insertAt(int, int) override;
    virtual void pop() override;
    virtual void push(int) override;
    virtual void print() override;
    virtual int getSize() override;
};

void DynamicArray::setCapacity(int newCapacity)
{
    int *newStorage = new int[newCapacity];

    // Copy the old storage to newStorage
    memcpy(newStorage, storage, sizeof(int) * size);
    capacity = newCapacity;
    // After having the newStorage, delete the old one
    delete[] storage;
    // Update the current storage to the new storage
    storage = newStorage;
}

// Ensure that the minCapacity that we need must smaller than the real capacity
void DynamicArray::ensureCapacity(int minCapacity)
{
    if (minCapacity > capacity)
    {
        int newCapacity = capacity * 3 / 2 + 1;
        if (newCapacity < minCapacity)
        {
            newCapacity = minCapacity;
        }
        setCapacity(newCapacity);
    }
}

// Make the capacity smaller so that it fits the size and do not waste memory
void DynamicArray::pack()
{
    if (size < capacity / 2 + 1)
    {
        int newCapacity = size * 3 / 2 + 1;
        // Update the new capacity
        setCapacity(newCapacity);
    }
}

// Make the capacity to totally fit the array (capa = size)
void DynamicArray::trim()
{
    int newCapacity = size;
    setCapacity(newCapacity);
}

// Check if the given arr[index] is in the arr
void DynamicArray::rangeCheck(int index)
{
    if (index < 0 || index >= size)
        throw "Index out of bound";
}

// Assign the arr[index] to the value
void DynamicArray::set(int index, int value)
{
    // Check if the index is valid
    rangeCheck(index);

    // We point to the memory address of storage[index]
    // Another way to write: storage[index] = value
    *(storage + index) = value;
}

// Get the storage[index]
int DynamicArray::get(int index)
{
    rangeCheck(index);
    return *(storage + index);
}

// Insert the value to the storage[index]
void DynamicArray::insertAt(int index, int value)
{
    if (index < 0 || index > size) // Allow insertion at size (append)
        throw "Index out of bound";
    ensureCapacity(size + 1);
    memmove(storage + index + 1, storage + index, sizeof(int) * (size - index));
    *(storage + index) = value;
    size++;
}

// Remove the storage[index]
void DynamicArray::removeAt(int index)
{
    rangeCheck(index);
    memmove(storage + index, storage + index + 1, sizeof(int) * (size - index - 1));
    size--;
    pack();
}

void DynamicArray::print()
{
    for (int i = 0; i < size; i++){
        int value = *(storage + i);
        cout << value << " ";
    }
    cout << endl;
}

void DynamicArray::push(int value)
{
    insertAt(size, value);
}


void DynamicArray::pop()
{
    if (size == 0) {
        throw "Cannot pop from empty array";
    }
    removeAt(size-1);
}

int DynamicArray::getSize()
{
    return this->size;
}

