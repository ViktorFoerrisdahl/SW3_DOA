#include <iostream>
#include "VectorHeap.h"

int main(void) {
    std::vector<int> v{};

    VectorHeap heap;

    std::cout << "isEmpty: " << heap.isEmpty() << std::endl;
    
    heap.insert(2);
    heap.insert(11);
    heap.insert(5);

    std::cout << "isEmpty: " << heap.isEmpty() << std::endl;
    std::cout << "size: " << heap.size() << std::endl;
    std::cout << "findMax: " << heap.findMax() << std::endl;
    
    std::cout << "deleteMax: " << heap.deleteMax() << std::endl;
    std::cout << "findMax: " << heap.findMax() << std::endl;
    std::cout << "size: " << heap.size() << std::endl;

    return 0;
}