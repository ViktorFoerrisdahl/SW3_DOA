#include <iostream>
#include <iterator>

#define TAL_VI_LEDER_EFTER 7
#define TAL2_VI_LEDER_EFTER 200

bool search(int *arr, int size, int target)
{
    if (size == 0)
    {
        return false;
    }

    if (arr[0] == target)
    {
        return true;
    }

    return search(arr + 1, size - 1, target);
}

int main()
{

    int array[9] = {1, 2, 3, 4, 200, 200000, 213123, 12312312, 213123};

    std::cout << "findes tallet " << TAL_VI_LEDER_EFTER << " i vores array? " << std::boolalpha << search(array, std::size(array) , TAL_VI_LEDER_EFTER);

    std::cout << std::endl;

    std::cout << "findes tallet " << TAL2_VI_LEDER_EFTER << " i vores array? " << std::boolalpha << search(array, std::size(array) , TAL2_VI_LEDER_EFTER);

    return 0;
}