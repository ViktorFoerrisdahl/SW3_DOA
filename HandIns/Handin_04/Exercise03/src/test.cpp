#include "min_heap_priority_queue.h"
#include <iostream>

int main()
{
    MinHeapPriorityQueue<int> queue;
    std::cout << std::boolalpha;

    std::cout << "Er køen tom? " << queue.empty() << '\n';

    // Indsætter tal til queue
    for (int value : {5, 2, 8, 1, 2})
    {
        queue.push(value);
    }

    std::cout << "Er køen tom efter indsættelse? " << queue.empty() << '\n';
    std::cout << "Mindste værdi: " << queue.top() << '\n'; 

    // Viser og fjerner det mindste tal, indtil køen er tom.
    std::cout << "Rækkefølge ved fjernelse: ";
    while (!queue.empty())
    {
        std::cout << queue.top() << ' ';
        queue.pop();
    }
    std::cout << '\n';

    std::cout << "Er køen tom til sidst? " << queue.empty() << '\n';
    return 0;
}
