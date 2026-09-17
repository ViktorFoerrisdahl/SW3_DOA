#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>

void printVector(std::vector<int>& vec) {
    std::cout << "M: ";
    for (auto element : vec){
        std::cout << element << ", ";
    }
    std::cout << "\n\n";
}

int main() {
    std::random_device rd;

    int M{};
    std::cout << "Enter M: "; // Receive input for M
    std::cin >> M;

    int N{};
    std::cout << "Enter N: ";
    std::cin >> N;

    std::vector<int> MContainer;

    // Loop #1: Generate vector of random Integers of M size
    for (int i = 1; i <= M; ++i) {
        srand(rd()); // O(1)
        int randomNum = rand() % 11; // Number between 0-10, O(1)
        MContainer.push_back(randomNum); // Amortized constant: O(1) assumed
    } // O(M)

    printVector(MContainer);

    // Loop #2: Generate N random integers and count
    std::cout << "N: ";
    int counter{};
    for (int i = 1; i <= N; ++i) {            
        srand(rd()); // O(1)
        int randomNum = rand() % 11; // Number between 0-10, O(1)
        std::cout << randomNum << ", "; // 1
        for (auto it = MContainer.begin(); it != MContainer.end(); ++it) {
            if (*it == randomNum) counter++; // 1
        } // O(M)
    } // O(N)

    std::cout << "\n\nCounter: ";
    std::cout << counter;

    return 0;
};