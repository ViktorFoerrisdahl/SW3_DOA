#include <iostream>

#include "selection_sort.h"
#include "test_selection_sort.h"

int main()
{
    std::cout << std::endl;

    std::cout << "Test of vector with type int:" << std::endl;
    test_std_vector_int();

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Test of vector with type float:" << std::endl;
    test_vector_float();

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Test of vector with type string:" << std::endl;
    test_vector_string();

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Test of empty vector:" << std::endl;
    test_vector_empty();

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Test of vector with one element:" << std::endl;
    test_vector_one_element();

    return 0;
}