#pragma once

#include <stdexcept>
#include "stack.h" 

template <typename Object>
class Queue {
private:
    Stack<Object> inStack;
    Stack<Object> outStack;

    // Helper method to transfer elements from inStack to outStack
    void shiftStacks() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.pop());
            }
        }
    }

public:
    Queue() = default;
    ~Queue() = default;

    bool empty() const {
        return inStack.empty() && outStack.empty();
    }

    int size() const {
        return inStack.size() + outStack.size();
    }

    void enqueue(const Object& x) {
        inStack.push(x);
    }

    Object dequeue() {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }
        shiftStacks();
        return outStack.pop();
    }

    Object front() {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }
        shiftStacks();
        return outStack.top();
    }
};