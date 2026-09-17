#pragma once
#include <vector>

class MaxHeap
{
public:
    // is the heap empty?
    virtual bool isEmpty() const = 0;

    // number of elements in the heap
    virtual int size() = 0;

    // add an element to the heap
    virtual void insert(const int x) = 0;

    // find the maximum element in the heap
    virtual const int findMax() const = 0;

    // delete and return the maximum element of the heap
    virtual int deleteMax() = 0;
};

class MyMaxHeap : public MaxHeap
{
private:
    std::vector<int> heap;

public:
    bool isEmpty() const override;
    int size() override;
    void insert(const int x) override;
    const int findMax() const override;
    int deleteMax() override;
};
