#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* data;
    void grow() {
        T* newData = new T[2 * cap];
        for (int i = 0; i < cap; i++) { // THIS IS AN O(N) OPERATION
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
    void push(T val) { // Amortized O(N)
        if (numElems == cap) { // Only O(N) if this is true
            grow();
        }
        data[numElems] = val;
        numElems++;
    }
    T pop() { // O(1)
        numElems--;
        return data[numElems];
    }
    T top() { // O(1)
        return data[numElems - 1];
    }
    int size() {
        return numElems;
    }
    int capacity() {
        return cap;
    }
};
int main() {
    Stack<int> stack(16);

    cout << "Stack capacity: " << stack.capacity() << endl;
    cout << "Stack occupancy: " << stack.size() << endl << endl;
    for (int i = 0; i < 34; i++) {
        stack.push(i);
        cout << "Stack capacity: " << stack.capacity() << endl;
        cout << "Stack occupancy: " << stack.size() << endl << endl;
    }
}