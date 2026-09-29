#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* data;
    void grow() {
        T* newData = new T[2 * cap];
        for (int i = 0; i < cap; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        cap = 2 * cap;
        return;
    }
    int cap;
    int numElems;
public:
    Stack(int x = 100) {
        cap = x;
        numElems = 0;
        data = new T[cap];
    }
    void push(T val) {
        if (numElems == cap) {
            grow();
        }
        data[numElems] = val;
        numElems++;
    }
    T pop() {
        numElems--;
        return data[numElems];
    }
    T top() {
        return data[numElems - 1];
    }
    bool isEmpty() const {
        return (numElems == 0);
    }
};


template <typename T>
class Queue {
private:
    Stack<T> stack;
    Stack<T> revStack;
public:
    void push(T val) {
        stack.push(val);
        return;
    }
    T pop() {
        while (not stack.isEmpty()) {
            revStack.push(stack.pop());
        }
        T val = revStack.pop();
        while (not revStack.isEmpty()) {
            stack.push(revStack.pop());
        }
        return val;
    }
    T front() {
        while (not stack.isEmpty()) {
            revStack.push(stack.pop());
        }
        T val = revStack.top();
        while (not revStack.isEmpty()) {
            stack.push(revStack.pop());
        }
        return val;
    }
};

int main() {
    Queue<int> queue;

    for (int i = 0; i < 18; i++) {
        queue.push(i);
    }
    for (int i = 0; i < 18; i++) {
        cout << "Pop item: " << queue.pop() << endl << endl;
    }
}