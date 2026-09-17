#include <algorithm>                                      // 0 runtime steps
#include <cstdlib>                                        // 0 runtime steps
#include <ctime>                                           // 0 runtime steps
#include <iostream>                                        // 0 runtime steps
#include <vector>                                          // 0 runtime steps

std::ostream& operator<<(                                   // 0 runtime steps
    std::ostream& os, const std::vector<int>& vec)          // 0 runtime steps
{                                                           // 0 runtime steps
    for (int value : vec)                                   // L iterations, L + 1 checks
    {                                                       // 0 runtime steps
        os << value << " ";                                // 2L stream operations: O(L)
    }                                                       // 0 runtime steps

    return os;                                              // 1 step
}                                                           // 0 runtime steps

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));  // O(1)

    int M = std::rand() % 101;                              // 1 step

    std::vector<int> vecM(M);                               // O(M)
    for (int i = 0; i < M; ++i)                             // 1 init + M + 1 checks + M increments
    {
        vecM[i] = std::rand() % 51;                         // M steps: O(M)
    }

    int N = std::rand() % 101;                              // 1 step

    std::vector<int> vecN(N);                               // O(N)
    for (int i = 0; i < N; ++i)                             // 1 init + N + 1 checks + N increments
    {
        vecN[i] = std::rand() % 51;                         // N steps
    }

    int count = 0;                                          // 1 step

    for (int i = 0; i < N; ++i)                             // 1 init + N + 1 checks + N increments
    {
        const auto it = std::find(                          // Værste tilfælde er M steps
            vecM.begin(),                                   // 1 step
            vecM.end(),                                     // 1 step
            vecN[i]);                                       // 1 step

        if (it != vecM.end())                               // N steps
        {
            ++count;                                        // Værste tilfælde er N steps
        }
    }  

    return 0;                                               // 1 step
}