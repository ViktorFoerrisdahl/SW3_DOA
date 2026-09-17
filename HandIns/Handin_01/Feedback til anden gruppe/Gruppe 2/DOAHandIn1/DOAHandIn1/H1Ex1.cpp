#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void Exercise1() {
    // Ensure different random sequences on each run
    srand(time(nullptr));

    // Our selections for M and N
    int M = 1000;
    int N = 500;

    // Generate M random integers between 0 and 999, and put them in vector A
    vector<int> A;
    for (int i = 0; i < M; i++) {
        A.push_back(rand() % 1000);
    }

    // Generate N random integers between 0 and 999, and count how many of them are in A using an iterator
    int count = 0;
    for (int j = 0; j < N; j++) {
        int target = rand() % 1000;

        // Search through A iteratively
        // Update count if integer is found at least once in A, then break loop
        for (vector<int>::const_iterator it = A.begin(); it != A.end(); ++it) {
            if (*it == target) {
                count++;
                break;
            }
        }
    }

    cout << "Number of N random integers found in A: " << count << endl;
}

int main() {
    Exercise1();
    return 0;
}