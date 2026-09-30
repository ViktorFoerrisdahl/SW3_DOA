#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <chrono>

#include "selection_sort.h"

void test_std_vector_int()
{
    std::vector<int> test_vector_not_sorted = {1, 2, 7, 8, 1, 3, 5, 2345, 3};

    selectionSort(test_vector_not_sorted);

    std::cout << "Own implemented selectionsort result: ";

    for (auto i : test_vector_not_sorted)
    {
        std::cout << i << ", ";
    }

    std::vector<int> test_vector_not_sorted1 = {1, 2, 7, 8, 1, 3, 5, 2345, 3};

    std::cout << std::endl
              << "result using std::sort:               ";

    std::sort(test_vector_not_sorted1.begin(), test_vector_not_sorted1.end());

    for (auto i : test_vector_not_sorted1)
    {
        std::cout << i << ", ";
    }
}

void test_vector_float()
{
    std::vector<float> test_vector_not_sorted = {1.2, 2.555, 7.1231, 8.8, 1.12, 3.123123, 5.23, 2345.3, 3};

    selectionSort(test_vector_not_sorted);

    std::cout << "Own implemented selectionsort result: ";

    for (auto i : test_vector_not_sorted)
    {
        std::cout << i << ", ";
    }

    std::vector<float> test_vector_not_sorted1 = {1.2, 2.555, 7.1231, 8.8, 1.12, 3.123123, 5.23, 2345.3, 3};

    std::cout << std::endl
              << "result using std::sort:               ";

    std::sort(test_vector_not_sorted1.begin(), test_vector_not_sorted1.end());

    for (auto i : test_vector_not_sorted1)
    {
        std::cout << i << ", ";
    }
}

void test_vector_string()
{
    std::vector<std::string> test_vector_not_sorted = {"a", "ba", "b", "ca", "abc", "banana", "apple", "cat"};

    selectionSort(test_vector_not_sorted);

    std::cout << "Own implemented selectionsort result: ";

    for (auto i : test_vector_not_sorted)
    {
        std::cout << i << ", ";
    }

    std::vector<std::string> test_vector_not_sorted1 = {"a", "ba", "b", "ca", "abc", "banana", "apple", "cat"};

    std::cout << std::endl
              << "result using std::sort:               ";

    std::sort(test_vector_not_sorted1.begin(), test_vector_not_sorted1.end());

    for (auto i : test_vector_not_sorted1)
    {
        std::cout << i << ", ";
    }
}

void test_vector_empty()
{
    std::vector<int> test_vector_not_sorted = {};

    selectionSort(test_vector_not_sorted);

    std::cout << "Own implemented selectionsort result: ";

    for (auto i : test_vector_not_sorted)
    {
        std::cout << i << ", ";
    }

    std::vector<int> test_vector_not_sorted1 = {};

    std::cout << std::endl
              << "result using std::sort:               ";

    std::sort(test_vector_not_sorted1.begin(), test_vector_not_sorted1.end());

    for (auto i : test_vector_not_sorted1)
    {
        std::cout << i << ", ";
    }
}

void test_vector_one_element()
{
    std::vector<int> test_vector_not_sorted = {2};

    selectionSort(test_vector_not_sorted);

    std::cout << "Own implemented selectionsort result: ";

    for (auto i : test_vector_not_sorted)
    {
        std::cout << i << ", ";
    }

    std::vector<int> test_vector_not_sorted1 = {2};

    std::cout << std::endl
              << "result using std::sort:               ";

    std::sort(test_vector_not_sorted1.begin(), test_vector_not_sorted1.end());

    for (auto i : test_vector_not_sorted1)
    {
        std::cout << i << ", ";
    }
}
