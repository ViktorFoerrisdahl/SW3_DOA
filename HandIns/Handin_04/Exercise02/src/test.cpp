#include <iostream>

#include "min_heap.h"

int main ()
{

    std::cout << "hello world! \n";

    MinHeap<int> H1; //danner vores heap

    int random_array[6] = {2,3,1,7,2,1};

    std::cout << "er vores heap tom? " << std::boolalpha << H1.isEmpty() << "\n";

    // H1.peek(); //programmet stoppes her, da vi kalder runtime error

    H1.insert(random_array[1]);
    
    std::cout << "er vores heap tom? " << std::boolalpha << H1.isEmpty() << "\n";

    std::cout << "peek: " << H1.peek() << "\n";

    return 0;
}