#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "introsort.h"

int main()
{
    std::vector<int> values = {5, 2, 4, 1, 3, 6, 18, 17, 16, 8, 7, 15, 13, 10, 12, 9, 11, 14};

    // Lille test af IntroSort foer tidsmaalingen.
    introSort(values);

    std::cout << "Sorteret vector: ";
    for (int value : values) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    // Samme seed giver samme input til alle cutoff-vaerdier.
    std::srand(42);
    const int repetitions = 20;
    std::cout << "useInsertion = " << useInsertion << "\n";

    for (int size : {100, 1000, 10000, 100000}) {
        std::vector<int> original(size);

        // Generer input foer maalingen: heltal fra 0 til 9999.
        auto f = []() { return std::rand() % 10000; };
        std::generate(original.begin(), original.end(), f);

        double totalTime = 0;
        for (int test = 0; test < repetitions; ++test) {
            std::vector<int> values = original; // Samme input i hver gentagelse

            auto start = std::chrono::high_resolution_clock::now();
            introSort(values); // Kun sorteringen maales
            auto stop = std::chrono::high_resolution_clock::now();

            auto duration = std::chrono::duration_cast<
                std::chrono::microseconds>(stop - start);
            totalTime += duration.count(); // Samlet tid i mikrosekunder

            // Kontroller resultatet efter maalingen
            if (!std::is_sorted(values.begin(), values.end())) {
                std::cout << "Fejl: vectoren er ikke sorteret!\n";
                return 1;
            }
        }

        std::cout << "N = " << size
                  << ": gennemsnit = " << totalTime / repetitions
                  << " mikrosekunder\n";
    }
}
