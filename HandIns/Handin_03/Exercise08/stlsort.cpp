#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
template<class T>
void show(vector<T> v) {
    cout << "[";
    for (T i:v)
        cout << i << ", "; 
    cout << "]";
}

int main() {
    // Undervisningens eksempel foer tidsmaalingen.
    vector<int> a = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    cout << "The vector before sorting is: \n";
    show(a);

    sort(a.begin(), a.end());

    cout << "\n \n The vector after sorting is: \n";
    show(a);

    cout << "\n";

    // Samme seed giver samme input som i opgave 8b.
    std::srand(42);
    const int repetitions = 20;
    std::cout << "std::sort\n";

    for (int size : {100, 1000, 10000, 100000}) {
        std::vector<int> original(size);

        // Generer input foer maalingen: heltal fra 0 til 9999.
        auto f = []() { return std::rand() % 10000; };
        std::generate(original.begin(), original.end(), f);

        double totalTime = 0;
        for (int test = 0; test < repetitions; ++test) {
            std::vector<int> values = original; // Samme input i hver gentagelse

            auto start = std::chrono::high_resolution_clock::now();
            std::sort(values.begin(), values.end()); // Kun sorteringen maales
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
    return 0;
}