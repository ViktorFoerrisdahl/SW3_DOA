#include <iostream>
#include "ordered_set.h"

int main()
{
    OrderedSet<int> set;

    // Test insert
    for (int value : {20, 10, 30, 5, 15, 25, 35})
    {
        set.insert(value);
    }


    // Test duplicate
    auto duplicate = set.insert(15);

    std::cout << "Duplicate insert returns: "
              << *duplicate << '\n';


    // Test begin(), end() and iterator++
    std::cout << "Ordered set: ";

    for (auto it = set.begin();
         it != set.end();
         ++it)
    {
        std::cout << *it << ' ';
    }

    std::cout << '\n';


    // Test find - existing element
    auto found = set.find(25);

    std::cout << "find(25): "
              << (found != set.end()
                      ? "found"
                      : "not found")
              << '\n';


    // Test find - missing element
    auto missing = set.find(99);

    std::cout << "find(99): "
              << (missing != set.end()
                      ? "found"
                      : "not found")
              << '\n';


    // Test erase on node with two children.
    // Before deletion, successor of 20 is 25.
    auto pos = set.find(20);

    auto next = set.erase(pos);

    std::cout
        << "After erase(20), returned iterator: ";

    if (next != set.end())
        std::cout << *next << '\n';
    else
        std::cout << "end\n";


    std::cout << "After erase: ";

    for (auto it = set.begin();
         it != set.end();
         ++it)
    {
        std::cout << *it << ' ';
    }

    std::cout << '\n';


    // Test copy constructor / deep copy
    OrderedSet<int> copy(set);

    copy.insert(100);


    std::cout << "Original: ";

    for (auto it = set.begin();
         it != set.end();
         ++it)
    {
        std::cout << *it << ' ';
    }

    std::cout << '\n';


    std::cout << "Copy:     ";

    for (auto it = copy.begin();
         it != copy.end();
         ++it)
    {
        std::cout << *it << ' ';
    }

    std::cout << '\n';


    return 0;
}