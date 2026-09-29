#pragma once

#include <stdexcept>

template <typename Object>
class Stack {
private:
    Object* array;
    int capacity;
    int topIndex;

    void resize();

public:
    Stack(int initialCapacity = 100);
    ~Stack();

    bool empty() const;
    int size() const;
    void push(const Object& x);
    Object pop();
    Object top() const;
};

#include "stack.cpp"
