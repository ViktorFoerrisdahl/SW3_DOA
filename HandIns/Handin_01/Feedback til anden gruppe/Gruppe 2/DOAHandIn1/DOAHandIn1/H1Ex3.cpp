#include <iostream>
#include <chrono> // For running time measurements

using namespace std;
using namespace std::chrono;

void fragment1(long long n) {
    long long sum = 0;
    for (long long i = 0; i < n; ++i) ++sum;
}

void fragment2(long long n) {
    long long sum = 0;
    for (long long i = 0; i < n; ++i)
        for (long long j = 0; j < n; ++j) ++sum;
}

void fragment3(long long n) {
    long long sum = 0;
    for (long long i = 0; i < n; ++i)
        for (long long j = 0; j < n * n; ++j) ++sum;
}

void fragment4(long long n) {
    long long sum = 0;
    for (long long i = 0; i < n; ++i)
        for (long long j = 0; j < i; ++j) ++sum;
}

// Calculate running-time for given code fragment and return milliseconds
double runningTime(const char* name, void (*fragment)(long long), long long n) {

    // Start timer
    auto t1 = high_resolution_clock::now();

    // Run code fragment
    fragment(n);

    // End timer
    auto t2 = high_resolution_clock::now();

    double elapsed_time = duration<double, milli>(t2 - t1).count();

    // Print running-time
    // Print given N
    cout << name << " (N = " << n << "): " << elapsed_time << " ms\n";

    return elapsed_time;
}

int main() {
    // Run test cases for each code fragment
    double f1_t0 = runningTime("Fragment 1", fragment1, 500000000);
    double f1_t1 = runningTime("Fragment 1", fragment1, 1000000000);
    cout << "\n";

    double f2_t0 = runningTime("Fragment 2", fragment2, 20000);
    double f2_t1 = runningTime("Fragment 2", fragment2, 40000);
    cout << "\n";

    double f3_t0 = runningTime("Fragment 3", fragment3, 750);
    double f3_t1 = runningTime("Fragment 3", fragment3, 1500);
    cout << "\n";

    double f4_t0 = runningTime("Fragment 4", fragment4, 30000);
    double f4_t1 = runningTime("Fragment 4", fragment4, 60000);
    cout << "\n";

    // Print growth rates of fragments
    cout << "Growth rates T(N_1)/T(N_0) \n";
    cout << "Fragment 1 growth rate: " << (f1_t1 / f1_t0) << "\n";
    cout << "Fragment 2 growth rate: " << (f2_t1 / f2_t0) << "\n";
    cout << "Fragment 3 growth rate: " << (f3_t1 / f3_t0) << "\n";
    cout << "Fragment 4 growth rate: " << (f4_t1 / f4_t0) << "\n";

    return 0;
}