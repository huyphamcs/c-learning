#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

class IDynamicArray
{
protected:
    int size;
    int capacity;
    int *storage;

public:
    IDynamicArray()
    {
        capacity = 10;
        size = 0;
        storage = new int[capacity];
    }

    IDynamicArray(int capacity)
    {
        this->capacity = capacity;
        size = 0;
        storage = new int[capacity];
    }

    virtual ~IDynamicArray()
    {
        delete[] storage;
    }

    virtual void setCapacity(int) = 0;
    virtual void ensureCapacity(int) = 0;
    virtual void pack() = 0;
    virtual void trim() = 0;
    virtual void rangeCheck(int) = 0;
    virtual void set(int, int) = 0;
    virtual int get(int) = 0;
    virtual void removeAt(int) = 0;
    virtual void insertAt(int, int) = 0;
    virtual void pop() = 0;
    virtual void push(int) = 0;
    virtual void print() = 0;
    virtual int getSize() = 0;
};

#endif