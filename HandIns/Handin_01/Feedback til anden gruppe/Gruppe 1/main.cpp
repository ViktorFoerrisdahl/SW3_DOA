#include <vector>
#include <iostream>
#include <chrono>
#include <functional>

void frag1(int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        ++sum;
    } // O(N)
}
void frag2(int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            ++sum;
        } // O(N)
    } // O(N^2)
}
void frag3(int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n * n; ++j)
        {
            ++sum;
        } // O(N^2)
    } // O(N^3)
}
void frag4(int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            ++sum;
        }
    }
}

void runtime_test(
    const std::string &test_name,
    const std::function<void(int)> &operation,
    const std::vector<int> &N_values)
{
    std::cout << "----------- Runtime test of " << test_name << " -----------\n";
    for (auto n_value : N_values)
    {
        auto t_start = std::chrono::steady_clock::now();
        operation(n_value);
        auto t_end = std::chrono::steady_clock::now();

        auto t_diff_us = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start);
        auto t_diff_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start);
        std::cout << "N = " << n_value << "\n";
        std::cout << "Elapsed: " << t_diff_us.count() << " us / " << t_diff_ms.count() << " ms\n\n";
    }
    std::cout << "\n\n\n";
}

int main()
{
    std::cout << "\n\n\n";
    runtime_test("Fragment #1", frag1, {250, 500, 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000});
    runtime_test("Fragment #2", frag2, {250, 500, 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000});
    runtime_test("Fragment #3", frag3, {250, 500, 1000, 2000, 4000}); // Fragment #3 is too slow for larger N values
    runtime_test("Fragment #4", frag4, {250, 500, 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000});
    return 0;
}