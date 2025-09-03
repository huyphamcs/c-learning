#include <iostream>
#include "src/SLinkedList.cpp"
#include "src/Stack.cpp"
#include <math.h>
using namespace std;

int main()
{
    // Test the Stack
    Stack<int>* myStack = new Stack<int>();
    
    cout << "Pushing numbers 0-9 to stack:" << endl;
    for (int i = 0; i < 10; i++)
    {
        myStack->push(i);
    }
    
    cout << "Original stack:" << endl;
    myStack->print();
    
    cout << "Stack size: " << myStack->getSize() << endl;
    cout << "Top element (peek): " << myStack->peek() << endl;
    
    cout << "\nCloning the stack:" << endl;
    IStack<int>* clonedStack = myStack->clone();
    clonedStack->print();
    
    cout << "\nPopping 3 elements from original:" << endl;
    for (int i = 0; i < 3; i++) {
        myStack->pop();
    }
    myStack->print();
    
    cout << "Cloned stack remains unchanged:" << endl;
    clonedStack->print();
    
    // Clean up
    delete myStack;
    delete clonedStack;
    
    return 0;
}