#include "stack.h"
#include <iostream>
#include <chrono>
#include <cassert>
#include <stdexcept>


int main () 
{
    stack minStack; //Tester default constructor

    std::cout << "Hvor mange pladser er der i arrayet lavet med default constructor? " << minStack.sizeOfStack() << std::endl;     
    
    stack minStack10000(10000); //tester constructor med parametre

    std::cout << "Hvor mange pladser er der i arrayet lavet med parameter i constructor? " << minStack10000.sizeOfStack() << std::endl; 
    
    
    // Tilføjer 10000 ting til vores array med 10000 pladser
    for (auto i = 0; i < 10000; i++) 
    {
        minStack10000.push(i);
    }

    std::cout << "Hvor mange pladser er der i arrayet efter vi har sat 10000 ting ind? " << minStack10000.sizeOfStack() << std::endl;   
    
    
    //Tilføjer en ting mere, som gerne skulle allokere en ny array med dobbelt så meget plads og ser hvor lang tid det tager via. chrono
    auto start = std::chrono::high_resolution_clock::now();

    minStack10000.push(10); 

    auto end = std::chrono::high_resolution_clock::now();

    auto us = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Hvor mange pladser er der i arrayet efter vi har sat 10001 ting ind? " << minStack10000.sizeOfStack() << std::endl;     

    std::cout << "Det tog " << us.count() << " us at lave push, da vi skulle genallokere hele arrayet fra 10000 til 20000" << std::endl;


    // tilføjer 9999 ting mere og derved skulle antallet af elementer være 20000
    for (auto i = 0; i < 9999; i++) 
    {
        minStack10000.push(i);
    }

    std::cout << "Hvor mange pladser er der i arrayet efter vi har sat 20000 ting ind? " << minStack10000.sizeOfStack() << std::endl; 


    //Tilføjer en ting mere, som gerne skulle allokere en ny array med dobbelt så meget plads og ser hvor lang tid det tager
    auto start1 = std::chrono::high_resolution_clock::now();

    minStack10000.push(10); 

    auto end1 = std::chrono::high_resolution_clock::now();

    auto us1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);

    std::cout << "Hvor mange pladser er der i arrayet efter vi har sat 20001 ting ind? " << minStack10000.sizeOfStack() << std::endl;     

    std::cout << "Det tog " << us1.count() << " us at lave push, da vi skulle genallokere hele arrayet" << std::endl;

    // Check that resizing inserts exactly one value and preserves LIFO order.
    stack small(1);
    small.push(10);
    small.push(20);
    assert(small.size() == 2);
    assert(small.sizeOfStack() == 2);
    assert(small.top() == 20);
    small.pop();
    assert(small.top() == 10);
    small.pop();
    assert(small.size() == 0);
    bool thrown = false;
    try { small.pop(); }
    catch (const std::out_of_range&) { thrown = true; }
    assert(thrown);
    thrown = false;
    try { small.top(); }
    catch (const std::out_of_range&) { thrown = true; }
    assert(thrown);
    thrown = false;
    try { stack invalid(0); }
    catch (const std::invalid_argument&) { thrown = true; }
    assert(thrown);
    std::cout << "Stack tests passed!" << std::endl;
    return 0;
}