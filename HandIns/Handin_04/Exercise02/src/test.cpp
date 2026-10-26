#include <iostream>

#include "min_heap.h"

#define test_af_peek_ved_tom_array 0 // Kan ændres fra 0 til 1. Bruges til slå peek til og fra ved test på tom array.

int main()
{

    std::cout << "hello world! \n"; // tester cout

    MinHeap<int> H1; // danner vores heap

    int random_array[11] = {10, 12, 13, 9, 7, 6, 1, 4, 2, 1, -2}; // array, som skal indsættes i heapen.

    std::cout << "er vores heap tom? " << std::boolalpha << H1.isEmpty() << "\n"; // tester isEmpty()

    if (test_af_peek_ved_tom_array)
    {
        H1.peek(); // programmet stoppes her, da vi kalder runtime error, hvis array er tom
    }

    for (auto e : random_array) // indsætter alle vores elemnenter ved brugt af insert()
    {
        H1.insert(e);
        std::cout << "peek vaerdi efter indsaettelse af " << e << ": " << H1.peek() << "\n"; // tester at minHeap opretholdes korrekt
    }

    // tester isEmpty efter indsættelse af elementer
    std::cout << "er vores heap tom? " << std::boolalpha << H1.isEmpty() << "\n";

    for (int i = 1; i <= 10; i++)
    {
        H1.remove();
        std::cout << "Vaerdi af peek efter " << i << " kald af remove: " << H1.peek() << "\n";
    }

    // indsætter lidt dubletter og sletter lidt undervejs
    H1.insert(1);
    std::cout << "peek vaerdi efter indsaettelse af " << 1 << ": " << H1.peek() << "\n"; // tester at minHeap opretholdes korrekt

    H1.insert(1);
    std::cout << "peek vaerdi efter indsaettelse af " << 1 << ": " << H1.peek() << "\n"; // tester at minHeap opretholdes korrekt

    H1.remove();
    std::cout << "peek vaerdi efter remove " << H1.peek() << "\n"; // tester at minHeap opretholdes korrekt

    H1.remove();
    std::cout << "peek vaerdi efter remove " << H1.peek() << "\n"; // tester at minHeap opretholdes korrekt

    H1.insert(1);
    std::cout << "peek vaerdi efter indsaettelse af " << 1 << ": " << H1.peek() << "\n"; // tester at minHeap opretholdes korrekt

    H1.insert(1);
    std::cout << "peek vaerdi efter indsaettelse af " << 1 << ": " << H1.peek() << "\n"; // tester at minHeap opretholdes korrekt

    H1.remove();
    std::cout << "peek vaerdi efter remove " << H1.peek() << "\n"; // tester at minHeap opretholdes korrekt

    H1.remove();
    std::cout << "peek vaerdi efter remove " << H1.peek() << "\n"; // tester at minHeap opretholdes korrekt

    H1.remove();
    std::cout << "peek vaerdi efter remove " << H1.peek() << "\n"; // tester at minHeap opretholdes korrekt

    return 0;
}