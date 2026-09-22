#include <iostream>

void triangle(int m, int n)
{
    if (m < n)
    {
        for (auto i = 0; i < m; i++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
        m++;
        triangle(m, n);
    }
    else if (m == n)
    {
        for (auto j = 0; j < 2; j++)
        {
            for (auto i = 0; i < m; i++)
            {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
        triangle(m,n);
    }
}

int main()
{
    triangle(2, 6);

    return 0;
}