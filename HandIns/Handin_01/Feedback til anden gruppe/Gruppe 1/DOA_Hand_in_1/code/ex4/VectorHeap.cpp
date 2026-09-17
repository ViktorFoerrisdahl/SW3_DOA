#include <vector>
#include <stdexcept>
#include  "VectorHeap.h"



bool VectorHeap::isEmpty() const
{
    return _heap.empty(); // O(1)
}

int VectorHeap::size()
{
    return _heap.size(); // O(1)
}

void VectorHeap::insert(const int x)
{
    _heap.push_back(x); // Amortized constant: O(1) assumed
}

const int VectorHeap::findMax() const
{
    if (_heap.empty())
        throw std::out_of_range("findMax() on empty heap"); // O(1)
    int max = *_heap.begin(); // O(1)
    for (auto it = _heap.begin(); it != _heap.end(); it++) {
        max = (*it > max) ? *it : max;
    } // O(n)
    return max;
}

int VectorHeap::deleteMax()
{
    if (_heap.empty())
        throw std::out_of_range("deleteMax() on empty heap"); // O(1)
    int max = *_heap.begin(); // O(1)
    auto it_max = _heap.begin(); // O(1)
    for (auto it = _heap.begin(); it != _heap.end(); it++) {
        if(*it > max) {
            max = *it;
            it_max = it;
        } // O(1)
    } // O(n)
    _heap.erase(it_max); // O(n)
    return max;
}
