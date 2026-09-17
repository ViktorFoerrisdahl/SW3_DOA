#include "heap.h"
#include "stdexcept"

bool MyMaxHeap::isEmpty() const
{
    return (heap.begin() == heap.end());
}

int MyMaxHeap::size()
{
    int heapSize = 0;
    if (isEmpty())
    {
        return heapSize;
    }
    else
    {
        for (auto it = heap.begin(); it != heap.end();)
        {
            heapSize++;
            it++;
        }
        return heapSize;
    }
}

void MyMaxHeap::insert(const int x)
{
    heap.push_back(x);
}

const int MyMaxHeap::findMax() const
{
    if (isEmpty())
    {
        throw std::runtime_error("findMax() kan ikke kaldes paa en tom heap");
    }
    int max = heap[0];
    for (auto it = heap.begin(); it != heap.end();)
    {
        if (*it > max)
        {
            max = *it;
        }
        it++;
    }
    return max;
}

int MyMaxHeap::deleteMax()
{
    if (isEmpty())
    {
        throw std::runtime_error("deleteMax() kan ikke kaldes paa en tom heap");
    }

    int tempMax = findMax();
    for (auto it = heap.begin(); it != heap.end();)
    {
        if (*it == tempMax)
        {
            it = heap.erase(it);
            break;
        }
        else
        {
            it++;
        }
    }

    return tempMax;
}