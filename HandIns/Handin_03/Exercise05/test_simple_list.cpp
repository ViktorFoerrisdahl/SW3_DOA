#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>
#include "simple_list.h"

void test_search()
{
    // test empty list
    List<int> list;
    std::cout << "Testing search on an empty list...\n";
    assert(list.search(67) == -1);
    std::cout << "Passed!\n";

    // test value not present
    list.push_back(7);
    list.push_back(2);
    list.push_back(4);
    list.push_back(6);
    list.push_back(7);
    list.push_back(67);

    std::cout << "Testing search when value is not present...\n";
    assert(list.search(69) == -1);
    std::cout << "Passed!\n";

    // test duplicate value
    std::cout << "Testing dublicate value - should return position of first match...\n";
    assert(list.search(7) == 0);
    std::cout << "Passed!\n";

    // test normal match
    std::cout << "Testing normal match...\n";
    assert(list.search(67) == 5);
    std::cout << "Passed!\n";
}

int main()
{
    test_search();
    std::cout << "All tests passed! \n";
}
