#ifndef INTROSORT_H
#define INTROSORT_H

/**
 * Order left, center, and right and hide the pivot.
 * Then compute partition, restore the pivot and return its position.
 */
#include <vector>
#include <utility>
#include <cassert>
#include <climits>
#include "insertion_sort.h"
using namespace std;

constexpr int useInsertion = 8; // Hoejst 8 elementer: brug Insertion Sort

template <typename Comparable>
int partition(vector<Comparable>& a, int left, int right) {
    assert(a.size() <= INT_MAX); // Stoerrelsen skal passe til int-indeks
    assert(left >= 0); // Startindeks maa ikke vaere negativt
    assert(right >= left && right - left >= 2); // Mindst tre elementer
    assert(static_cast<size_t>(right) < a.size()); // Slutindeks er i vectoren

    int center = left + (right - left) / 2;

    // Median-of-three: ordn de tre vaerdier, saa a[center] bliver pivot.
    if (a[center] < a[left])
        std::swap(a[left], a[center]);
    if (a[right] < a[left])
        std::swap(a[left], a[right]);
    if (a[right] < a[center])
        std::swap(a[center], a[right]);

    // Place pivot at position right - 1
    std::swap(a[center], a[right - 1]);

    // Now the partitioning
    Comparable& pivot = a[right - 1];
    int i = left, j = right - 1;

    // Find vaerdier paa forkert side af pivot; endepunkterne stopper scanningerne.
    do {
        while (a[++i] < pivot) {}
        while (pivot < a[--j]) {}
        if (i < j) {
            std::swap(a[i], a[j]);
        }
    } while (i < j);

    std::swap(a[i], a[right - 1]); // Restore pivot
    return i;
}

/**
 * Internal quicksort method that makes recursive calls.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
// left og right er begge inkluderet i delomraadet.
template <typename Comparable>
void introSort(vector<Comparable>& a, int left, int right) {
    assert(useInsertion >= 2); // To elementer skal bruge Insertion Sort
    assert(a.size() <= INT_MAX);
    assert(left >= 0 && static_cast<size_t>(left) <= a.size());
    assert(right >= -1 &&
           (right == -1 || static_cast<size_t>(right) < a.size()));
    assert(left <= right + 1); // Tillad ogsaa et tomt delomraade

    if (left >= right) {
        return; // Nul eller et element er allerede sorteret
    }

    int size = right - left + 1; // Begge ender er inkluderet

    if (size <= useInsertion) {
        // Do an insertion sort on the subarray
        insertionSort(a.begin() + left, a.begin() + right + 1); // Sorter det lille delomraade
    } else {
        int i = partition(a, left, right); // Placer pivot
        introSort(a, left, i - 1);  // Sort small elements
        introSort(a, i + 1, right); // Sort large elements
        // Pivot ved i er allerede paa sin endelige plads
    }
}

/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable>
void introSort(vector<Comparable>& a) {
    assert(a.size() <= INT_MAX);

    if (a.empty()) {
        return; // En tom vector skal ikke sorteres
    }

    introSort(a, 0, static_cast<int>(a.size()) - 1); // Sorter hele vectoren
}

#endif
