#include <vector>
#include <algorithm>

template <class T>
void selectionSort(std::vector<T> &values)
{
    for (std::size_t i = 0; i + 1 < values.size(); i++) // Kører N−1 gange, da det sidste element automatisk står korrekt, når de øvrige er på plads. i + 1 < size undgår underflow ved en tom vektor.
    {
        std::size_t current_smallest_value_index{i};        // angiver det indeks, som vi er kommet til i for-loopet som det mindste.
        for (std::size_t j = i + 1; j < values.size(); j++) // tjekker resten af vektor fra i + 1 til slutningen, da vi ikke skal lave om på de allerede fundne mindste vaerdier, som vi allerede har swappet, mens vi heller ikke skal tjekke i = j, da det er det samme element.
        {
            if (values[current_smallest_value_index] > values[j]) // hvis det nye tal er mindre end vores nuvaerende mindste tal
            {
                current_smallest_value_index = j; // indeks til det mindste tal opdateres
            }
        }
        std::swap(values[i], values[current_smallest_value_index]); // efter det inderste for-loop, som finder det indeks, som den mindste vaerdi står på laves swap med det og indeks i, som vi er kommet til.
    }
}