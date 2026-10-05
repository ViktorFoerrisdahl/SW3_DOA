#include <cassert>
#include <iostream>
#include "counting_sort.h"

void test_counting_sort()
{
    std::vector<int> values;
    std::cout << "Testing empty vector...\n";
    countingSort(values);
    assert(values.empty());
    std::cout << "Passed!\n";

    std::cout << "Testing single element...\n";
    values = {1};
    countingSort(values);
    assert(values.size() == 1);
    assert(values[0] == 1);
    std::cout << "Passed!\n";

    std::cout << "Testing unsorted vector with duplicates...\n";
    values = {6, 2, 0, 2, 6, 1};
    countingSort(values);
    std::vector<int> expected = {0, 1, 2, 2, 6, 6};
    std::cout << "Expected: 0, 1, 2, 2, 6, 6,\nActual:   ";
    for (int value : values)
        std::cout << value << ", ";
    std::cout << '\n';
    assert(values == expected);
    std::cout << "Passed!\n";
}

int main()
{
    test_counting_sort();
    std::cout << "All tests passed!\n";
}
