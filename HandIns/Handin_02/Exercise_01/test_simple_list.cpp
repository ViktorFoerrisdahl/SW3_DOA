#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>
#include "simple_list.h"

void test_empty_list()
{
    List<int> list;
    assert(list.size() == 0);
    assert(list.empty());
    assert(!list.contains(42));
}

void test_insertion()
{
    List<int> list;
    list.push_front(10);
    list.push_front(12);
    list.push_back(14);
    list.insert(5, 1);
    list.insert(3, 0);
    list.insert(20, list.size());

    std::cout << "Expected: 3, 12, 5, 10, 14, 20,\nActual:   ";
    list.print();
    std::cout << std::endl;
    assert(list.size() == 6);
    int expected[] = {3, 12, 5, 10, 14, 20};
    for (int i = 0; i < 6; i++)
        assert(list.find_kth(i) == expected[i]);

    List<int> other;
    other.push_back(7);
    assert(other.find_kth(0) == 7);
    other.clear();
    other.insert(8, 0);
    assert(other.find_kth(0) == 8);
}

void test_removal()
{
    List<int> list;
    for (int value = 10; value <= 60; value += 10)
        list.push_back(value);

    int removed = list.pop_front();
    assert(removed == 10);
    removed = list.pop_back();
    assert(removed == 60);
    removed = list.remove(1);
    assert(removed == 30);

    std::cout << "Expected: 20, 40, 50,\nActual:   ";
    list.print();
    std::cout << std::endl;
    assert(list.size() == 3);
    assert(list.find_kth(0) == 20);
    assert(list.find_kth(1) == 40);
    assert(list.find_kth(2) == 50);

    removed = list.remove(0);
    assert(removed == 20);
    removed = list.remove(list.size() - 1);
    assert(removed == 50);
    removed = list.remove(0);
    assert(removed == 40);
    assert(list.empty());

    list.push_front(1);
    removed = list.pop_front();
    assert(removed == 1);
    assert(list.empty());
    list.push_back(2);
    removed = list.pop_back();
    assert(removed == 2);
    assert(list.empty());
}

void test_search()
{
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    assert(list.find_kth(0) == 10);
    assert(list.find_kth(1) == 20);
    assert(list.find_kth(2) == 30);
    assert(list.contains(20));
    assert(!list.contains(99));
}

void test_clear()
{
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.clear();
    assert(list.empty());
    assert(list.size() == 0);
    list.clear();
    assert(list.empty());
    list.push_back(30);
    assert(list.size() == 1);
    assert(list.find_kth(0) == 30);
}

void test_reverse()
{
    List<int> list;
    list.reverse();
    assert(list.empty());
    list.push_back(10);
    list.reverse();
    assert(list.find_kth(0) == 10);
    list.push_back(20);
    list.push_back(30);
    list.reverse();
    assert(list.size() == 3);
    assert(list.find_kth(0) == 30);
    assert(list.find_kth(1) == 20);
    assert(list.find_kth(2) == 10);
    list.reverse();
    assert(list.find_kth(0) == 10);
    assert(list.find_kth(1) == 20);
    assert(list.find_kth(2) == 30);
}

void test_print()
{
    List<int> list;
    std::cout << "Empty list: ";
    list.print();
    std::cout << std::endl;
    list.push_back(10);
    list.push_back(20);
    std::cout << "Expected: 10, 20,\nActual:   ";
    list.print();
    std::cout << std::endl;
    assert(list.size() == 2);
    assert(list.find_kth(0) == 10);
    assert(list.find_kth(1) == 20);
}

void test_invalid_operations()
{
    List<int> list;
    bool thrown = false;
    try
    {
        list.pop_front();
    }
    catch (const std::out_of_range &)
    {
        thrown = true;
    }
    assert(thrown);

    thrown = false;
    try
    {
        list.pop_back();
    }
    catch (const std::out_of_range &)
    {
        thrown = true;
    }
    assert(thrown);

    thrown = false;
    try
    {
        list.remove(0);
    }
    catch (const std::out_of_range &)
    {
        thrown = true;
    }
    assert(thrown);

    list.push_back(10);
    int invalidInsertPositions[] = {-1, 2};
    for (int i = 0; i < 2; i++)
    {
        int pos = invalidInsertPositions[i];
        thrown = false;
        try
        {
            list.insert(20, pos);
        }
        catch (const std::out_of_range &)
        {
            thrown = true;
        }
        assert(thrown);
    }
    int invalidPositions[] = {-1, 1};
    for (int i = 0; i < 2; i++)
    {
        int pos = invalidPositions[i];
        thrown = false;
        try
        {
            list.remove(pos);
        }
        catch (const std::out_of_range &)
        {
            thrown = true;
        }
        assert(thrown);

        thrown = false;
        try
        {
            list.find_kth(pos);
        }
        catch (const std::out_of_range &)
        {
            thrown = true;
        }
        assert(thrown);
    }
    assert(list.size() == 1);
    assert(list.find_kth(0) == 10);
}

int main()
{
    std::cout << "Testing empty list..." << std::endl;
    test_empty_list();
    std::cout << "PASS" << std::endl;

    std::cout << "Testing insertion..." << std::endl;
    test_insertion();
    std::cout << "PASS" << std::endl;

    std::cout << "Testing removal..." << std::endl;
    test_removal();
    std::cout << "PASS" << std::endl;

    std::cout << "Testing search..." << std::endl;
    test_search();
    std::cout << "PASS" << std::endl;

    std::cout << "Testing clear..." << std::endl;
    test_clear();
    std::cout << "PASS" << std::endl;

    std::cout << "Testing print..." << std::endl;
    test_print();
    std::cout << "PASS" << std::endl;

    std::cout << "Testing invalid operations..." << std::endl;
    test_invalid_operations();
    std::cout << "PASS" << std::endl;

    std::cout << "Testing reverse..." << std::endl;
    test_reverse();
    std::cout << "PASS" << std::endl;

    std::cout << "All tests passed! \n";
}
