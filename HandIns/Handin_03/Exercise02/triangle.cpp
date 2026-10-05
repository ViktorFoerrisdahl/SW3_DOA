#include <iostream>

void printStars(int s)
{
    for (auto i = 0; i < s; i++)
    {
        std::cout << "*";
    }
    std::cout << std::endl;
}

void triangle(int m, int n)
{
    if (m < n)
    {
        printStars(m);
        triangle(m + 1, n);
    }

    if (m == n)
    {
        printStars(m);
    }

    printStars(m);
}

int main()
{
    triangle(4, 4);

    return 0;
}