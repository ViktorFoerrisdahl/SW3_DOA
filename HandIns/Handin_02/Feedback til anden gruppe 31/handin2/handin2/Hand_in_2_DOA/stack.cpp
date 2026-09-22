#include "stack.h"

template <typename Object>
Stack<Object>::Stack(int initialCapacity) {
    if (initialCapacity <= 0) initialCapacity = 100;
    capacity = initialCapacity;
    array = new Object[capacity];
    topIndex = -1;
}

template <typename Object>
Stack<Object>::~Stack() {
    delete[] array;
}

template <typename Object>
void Stack<Object>::resize() {
    int newCapacity = capacity * 2;
    Object* newArray = new Object[newCapacity];

    for (int i = 0; i <= topIndex; ++i) {
        newArray[i] = array[i];
    }

    delete[] array;
    array = newArray;
    capacity = newCapacity;
}

template <typename Object>
bool Stack<Object>::empty() const {
    return topIndex == -1;
}

template <typename Object>
int Stack<Object>::size() const {
    return topIndex + 1;
}

template <typename Object>
void Stack<Object>::push(const Object& x) {
    if (topIndex + 1 == capacity) {
        resize();
    }
    array[++topIndex] = x;
}

template <typename Object>
Object Stack<Object>::pop() {
    if (empty()) {
        throw std::underflow_error("Stack is empty");
    }
    return array[topIndex--];
}

template <typename Object>
Object Stack<Object>::top() const {
    if (empty()) {
        throw std::underflow_error("Stack is empty");
    }
    return array[topIndex];
}