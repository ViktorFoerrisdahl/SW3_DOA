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

    // Til step 4 test:
    // std::cout << "arr[0] = " << arr[0] << " size = " << size << std::endl;

    return search(arr + 1, size - 1, target);
}

int max(int *arr, int size, int currentMax)
{
    if (size == 0)
    {
        return currentMax;
    }

    if (arr[0] > currentMax)
    {
        currentMax = arr[0];
    }

    // Til step 4 test:
    std::cout << "arr[0] = " << arr[0] << " size = " << size << " currentMax: " << currentMax << std::endl;

    return max(arr + 1, size - 1, currentMax);
}

int min(int *arr, int size, int currentMin)
{
    if (size == 0)
    {
        return currentMin;
    }

    if (arr[0] < currentMin)
    {
        currentMin = arr[0];
    }

    // Til step 4 test:
    std::cout << "arr[0] = " << arr[0] << " size = " << size << " currentMin: " << currentMin << std::endl;

    return min(arr + 1, size - 1, currentMin);
}


int main()
{
    int array[10] = {-89, 1, 2, 3, 4, 200, 200000, 213123, 132323, 10000000};

    // std::cout << "findes tallet " << TAL_VI_LEDER_EFTER << " i vores array? " << std::endl << std::boolalpha << search(array, std::size(array) , TAL_VI_LEDER_EFTER);

    // std::cout << std::endl;

    // std::cout << "findes tallet " << TAL2_VI_LEDER_EFTER << " i vores array? " << std::boolalpha << search(array, std::size(array) , TAL2_VI_LEDER_EFTER);

    // std::cout << std::endl;

    std::cout << "Max i vores array er:  " << std::endl << max(array, std::size(array), array[0]);

    // std::cout << std::endl;

    // std::cout << "Min i vores array er:  " << min(array, std::size(array), array[0]);

    return 0;
}