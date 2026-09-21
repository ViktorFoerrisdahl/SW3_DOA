#include "dictionary.h"
#include <cassert>

int main()
{
    Dictionary dictionary;

    dictionary.insert(10, 100);
    dictionary.insert(20, 200);
    dictionary.insert(30, 300);

    std::cout << "Initial dictionary:" << std::endl;
    dictionary.print();


    int value;

    if (dictionary.get(20, value))
    {
        std::cout << "\nValue for key 20: "
                  << value << std::endl;
    }
    else
    {
        std::cout << "\nKey not found." << std::endl;
    }


    if (dictionary.update(20, 250))
    {
        std::cout << "\nKey 20 updated." << std::endl;
    }

    dictionary.print();


    if (dictionary.remove(10))
    {
        std::cout << "\nKey 10 removed." << std::endl;
    }

    dictionary.print();

    assert(!dictionary.insert(20, 999));
    assert(dictionary.get(20, value));
    assert(value == 250);
    assert(!dictionary.get(10, value));
    assert(!dictionary.remove(99));
    assert(!dictionary.update(99, 123));
    std::cout << "Dictionary tests passed!" << std::endl;
    return 0;
}
