#pragma once

#include "priority_queue.h"
#include "min_heap.h"

template <typename T>
class MinHeapPriorityQueue : public PriorityQueue<T>
{
public:
    void push(const T& x) override
    {
        heap.insert(x); // Indsætter elementet i vores min-heap
    }

    void pop() override
    {
        heap.remove(); // Fjerner det mindste element
    }

    T top() override
    {
        return heap.peek(); // Returnerer det mindste element uden at fjerne det
    }

    bool empty() const override
    {
        return heap.isEmpty(); // Tjekker, om heapen er tom
    }

private:
    MinHeap<T> heap; // Vi genbruger heapen fra opgave 2
};
