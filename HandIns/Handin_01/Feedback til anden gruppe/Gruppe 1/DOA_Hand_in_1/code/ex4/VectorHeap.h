#include <vector>
#include "MaxHeap.h"

#pragma once

class VectorHeap : public MaxHeap {
public:
    // is the heap empty?
    bool isEmpty() const override;
    // number of elements in the heap
    int size() override;
    // add an element to the heap
    void insert(const int x) override;
    // find the maximum element in the heap
    const int findMax() const override;
    // delete and return the maximum element of the heap
    int deleteMax() override;

private:
    std::vector<int> _heap;
};