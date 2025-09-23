#include <iostream>
#include "include/RoundBuffer.h"

using namespace std;

void testBasicOperations() {
    cout << "\n=== Test 1: Basic Operations ===" << endl;
    RoundBuffer<int> buffer(5);
    
    cout << "Buffer created with capacity 5" << endl;
    cout << "Is empty: " << (buffer.isEmpty() ? "Yes" : "No") << endl;
    cout << "Size: " << buffer.getSize() << "/" << buffer.getCapacity() << endl;
    
    // Push elements
    for (int i = 1; i <= 3; i++) {
        buffer.push(i);
        cout << "Pushed " << i << ", Size: " << buffer.getSize() << endl;
    }
    
    buffer.print();
    
    // Pop elements
    while (!buffer.isEmpty()) {
        int value = buffer.pop();
        cout << "Popped: " << value << ", Size: " << buffer.getSize() << endl;
    }
}

void testCircularBehavior() {
    cout << "\n=== Test 2: Circular Buffer Behavior ===" << endl;
    RoundBuffer<int> buffer(3);
    
    // Fill buffer
    for (int i = 1; i <= 3; i++) {
        buffer.push(i);
    }
    cout << "Buffer filled: ";
    buffer.print();
    
    // Pop one and push one to test circular nature
    int popped = buffer.pop();
    cout << "Popped: " << popped << endl;
    
    buffer.push(4);
    cout << "Pushed 4: ";
    buffer.print();
    
    // Pop another and push another
    popped = buffer.pop();
    cout << "Popped: " << popped << endl;
    
    buffer.push(5);
    cout << "Pushed 5: ";
    buffer.print();
}

void testOverflowAndUnderflow() {
    cout << "\n=== Test 3: Overflow and Underflow Handling ===" << endl;
    RoundBuffer<int> buffer(2);
    
    // Fill buffer to capacity
    buffer.push(1);
    buffer.push(2);
    cout << "Buffer is full: " << (buffer.isFull() ? "Yes" : "No") << endl;
    
    // Test overflow
    try {
        buffer.push(3);
    } catch (const overflow_error& e) {
        cout << "Overflow caught: " << e.what() << endl;
    }
    
    // Empty buffer
    buffer.pop();
    buffer.pop();
    cout << "Buffer is empty: " << (buffer.isEmpty() ? "Yes" : "No") << endl;
    
    // Test underflow
    try {
        buffer.pop();
    } catch (const underflow_error& e) {
        cout << "Underflow caught: " << e.what() << endl;
    }
}

void testWithDifferentTypes() {
    cout << "\n=== Test 4: Different Data Types ===" << endl;
    
    // Test with strings
    RoundBuffer<string> stringBuffer(3);
    stringBuffer.push("Hello");
    stringBuffer.push("World");
    stringBuffer.push("!");
    
    cout << "String buffer: ";
    stringBuffer.print();
    
    // Test with doubles
    RoundBuffer<double> doubleBuffer(3);
    doubleBuffer.push(3.14);
    doubleBuffer.push(2.71);
    doubleBuffer.push(1.41);
    
    cout << "Double buffer: ";
    doubleBuffer.print();
}

void testClearOperation() {
    cout << "\n=== Test 5: Clear Operation ===" << endl;
    RoundBuffer<int> buffer(5);
    
    for (int i = 1; i <= 5; i++) {
        buffer.push(i);
    }
    
    cout << "Before clear: ";
    buffer.print();
    
    buffer.clear();
    cout << "After clear: ";
    buffer.print();
    
    cout << "Is empty after clear: " << (buffer.isEmpty() ? "Yes" : "No") << endl;
}

void testLargeOperations() {
    cout << "\n=== Test 6: Large Operations ===" << endl;
    RoundBuffer<int> buffer(100);
    
    // Push 50 elements
    for (int i = 1; i <= 50; i++) {
        buffer.push(i);
    }
    
    cout << "Pushed 50 elements, Size: " << buffer.getSize() << endl;
    
    // Pop 25 elements
    for (int i = 0; i < 25; i++) {
        buffer.pop();
    }
    
    cout << "Popped 25 elements, Size: " << buffer.getSize() << endl;
    
    // Push 25 more elements to test circular wrapping
    for (int i = 51; i <= 75; i++) {
        buffer.push(i);
    }
    
    cout << "Pushed 25 more elements, Size: " << buffer.getSize() << endl;
    
    // Show first few elements
    cout << "First 10 elements: ";
    for (int i = 0; i < 10; i++) {
        cout << buffer.pop() << " ";
    }
    cout << endl;
}

int main() {
    cout << "RoundBuffer Comprehensive Test Suite" << endl;
    cout << "====================================" << endl;
    
    testBasicOperations();
    testCircularBehavior();
    testOverflowAndUnderflow();
    testWithDifferentTypes();
    testClearOperation();
    testLargeOperations();
    
    cout << "\n=== All Tests Completed ===" << endl;
    return 0;
}