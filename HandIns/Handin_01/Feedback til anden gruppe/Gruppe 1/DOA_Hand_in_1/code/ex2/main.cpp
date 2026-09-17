#include <iostream>
#include <math.h>
#include <chrono>

int myMethod(int N)
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N * sqrt(N); k++) {
                x++;
            } // N*sqrt(N)
        } // N*(N*sqrt(N))
    } // N*(N*(N*sqrt(N)))
    for (int i = 0; i < N * N; i++) {
        y++;
    } // N*N
 
    return x + y;
}

int main(void) {
    int N{};
    std::cout << "Input N: ";
    std::cin >> N;

    auto t_start = std::chrono::steady_clock::now();
    int xy = myMethod(N);
    auto t_end = std::chrono::steady_clock::now();

    // std::cout << "x + y: " << xy << '\n';

    auto t_diff = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start);

    std::cout << "Elapsed: " << t_diff.count() << " us\n";

    return 0;
}