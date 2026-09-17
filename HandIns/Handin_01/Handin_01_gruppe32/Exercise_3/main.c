#include <time.h>
#include <stdio.h>

long long fragment1(int n)
{
    long long sum = 0;
    
    for (int i = 0; i < n; ++i)
    {
        ++sum;
    } 

    return sum;
}

long long fragment2(int n)
{
    long long sum = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            ++sum;
        }
    }

    return sum;
}

long long fragment3(int n)
{
    long long sum = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n * n; ++j)
        {
            ++sum;
        }
    }

    return sum;
}

long long fragment4(int n)
{
    long long sum = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            ++sum;
        }
    }

    return sum;
}

void testFragment1(void)
{
    int values[] = {
        10000000,
        20000000,
        40000000,
        80000000,
    };

    int count = sizeof(values) / sizeof(values[0]);

    printf("Fragment 1:\n");

    for (int i = 0; i < count; i++)
    {
        int n = values[i];

        clock_t start = clock();

        long long result = fragment1(n);

        clock_t end = clock();

        double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

        printf("n = %d, sum = %lld, time = %.6f seconds\n", n, result, elapsed);
    }
}

void testFragment2(void)
{
    int values[] = {
        2000,
        4000,
        8000,
        16000,
    };

    int count = sizeof(values) / sizeof(values[0]);

    printf("\nFragment 2:\n");

    for (int i = 0; i < count; i++)
    {
        int n = values[i];

        clock_t start = clock();

        long long result = fragment2(n);

        clock_t end = clock();

        double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

        printf("n = %d, sum = %lld, time = %.6f seconds\n", n, result, elapsed);
    }
}

void testFragment3(void)
{
    int values[] = {
        100,
        200,
        400,
        800,
    };

    int count = sizeof(values) / sizeof(values[0]);

    printf("\nFragment 3:\n");

    for (int i = 0; i < count; i++)
    {
        int n = values[i];

        clock_t start = clock();

        long long result = fragment3(n);

        clock_t end = clock();

        double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

        printf("n = %d, sum = %lld, time = %.6f seconds\n", n, result, elapsed);
    }
}

void testFragment4(void)
{
    int values[] = {
        2000,
        4000,
        8000,
        16000,
    };

    int count = sizeof(values) / sizeof(values[0]);

    printf("\nFragment 4:\n");

    for (int i = 0; i < count; i++)
    {
        int n = values[i];

        clock_t start = clock();

        long long result = fragment4(n);

        clock_t end = clock();

        double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

        printf("n = %d, sum = %lld, time = %.6f seconds\n", n, result, elapsed);
    }
}


int main() 
{
    testFragment1();
    testFragment2();
    testFragment3();
    testFragment4();

    return 0;
}
