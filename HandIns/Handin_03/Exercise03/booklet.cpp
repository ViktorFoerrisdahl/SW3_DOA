#include <iostream>

void bookletPrintHelp(int startPage, int endPage, int sheetnumber) // Ekstra funktion lavet, så der kan tælles et sheetnummer (sheetnumber)
{
    std::cout << "Sheet " << sheetnumber << " contains pages "
              << startPage << ", " << startPage + 1 << ", " << endPage - 1 << ", " << endPage << "\n"; // Printer antallet af brugte sheets og siderne printet på papiret

    if (endPage - startPage < 4) // Svarer til, at basecasen er klaret og printet tidligere, og funktionen må derfor stoppe
    {
        return;
    }

    bookletPrintHelp(startPage + 2, endPage - 2, sheetnumber + 1); // Kalder den recursive case, hvor den bruger de nye sidetal og et opdateret sheetnummer
}

void bookletPrint(int startPage, int endPage) // Den originale funktion, der skulle laves
{
    bookletPrintHelp(startPage, endPage, 1); // Kalder den ekstra hjælpefunktion med sheetnumber
}

int main()
{ // Tester forskellige værdier
    bookletPrint(1, 8);
    bookletPrint(1, 12);
    bookletPrint(1, 4);
}