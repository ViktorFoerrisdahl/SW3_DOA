#include <iostream>
#include <iterator>
#include <cassert>

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

    // Til step 4 test:
    // std::cout << "arr[0] = " << arr[0] << " size = " << size << std::endl;

    return search(arr + 1, size - 1, target);
}

int max(int *arr, int size)
{
    assert(size > 0); // Stopper funktionen, hvis følgende er false og returnerer en fejlbesked. Der kan nemlig ikke findes en max af et tomt array

    if (size == 1)
    {
        return arr[0];
    }

    int maxOfRest = max(arr + 1, size - 1);

    // Til step 4 test:
    // std::cout << "arr[0] = " << arr[0] << "   size = " << size << "   maxOfRest: " << maxOfRest << std::endl;

    if (arr[0] > maxOfRest)
    {
        return arr[0];
    }
    return maxOfRest;
}

int min(int *arr, int size)
{
    assert(size > 0); // Stopper funktionen, hvis følgende er false og returnerer en fejlbesked. Der kan nemlig ikke findes en max af et tomt array

    if (size == 1)
    {
        return arr[0];
    }

    int minOfRest = min(arr + 1, size - 1);

    // Til step 4 test:
    std::cout << "arr[0] = " << arr[0] << "   size = " << size << "   minOfRest: " << minOfRest << std::endl;

    if (arr[0] < minOfRest)
    {
        return arr[0];
    }
    return minOfRest;
}

int main()
{
    int array[10] = {-89, 1, 2, 3, 4, 200, 200000, 213123, 132323, 10000000};

    std::cout << "findes tallet " << TAL_VI_LEDER_EFTER << " i vores array? " << std::boolalpha << search(array, std::size(array), TAL_VI_LEDER_EFTER);

    std::cout << std::endl;

    std::cout << "findes tallet " << TAL2_VI_LEDER_EFTER << " i vores array? " << std::boolalpha << search(array, std::size(array), TAL2_VI_LEDER_EFTER);

    std::cout << std::endl;

    // std::cout << "Max i vores array er:  " << std::endl << max(array, std::size(array));

    std::cout << std::endl;

    std::cout << "Min i vores array er:  " << std::endl << min(array, std::size(array));

    return 0;
}