#include "heap.h"
#include <iostream>


int main()
{
    MyMaxHeap heap1;

    std::cout << "er heap tom?: " << heap1.isEmpty() << std::endl;

    std::cout << "hvad er size paa heap?: " << heap1.size() << std::endl;

    // std::cout << "hvad er max paa heap?: " << heap1.findMax() << std::endl;
    
    heap1.insert(12);
    heap1.insert(122);
    heap1.insert(123);
    heap1.insert(1211);    
    heap1.insert(1211);    
    heap1.insert(1211);    
    heap1.insert(1);

    std::cout << "er heap tom?: " << heap1.isEmpty() << std::endl;

    std::cout << "hvad er size paa heap?: " << heap1.size() << std::endl;

    std::cout << "hvad er max paa heap?: " << heap1.findMax() << std::endl;

    std::cout << "Sletter nu max...... og printer den ud:" << std::endl;

    std::cout << "max heap element, som slettes: " << heap1.deleteMax() << std::endl;

    std::cout << "hvad er size paa heap?: " << heap1.size() << std::endl;

    std::cout << "hvad er max paa heap?: " << heap1.size() << std::endl;

    return 0;
}