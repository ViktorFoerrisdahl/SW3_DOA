#include <iostream>
#include <string>
#include "simple_list.h"
#include "simple_linked_list.h"

using namespace std;

int main() {
    LinkedList<int> list;

    cout << "LINKED LIST TEST" << endl;

    // 1. Test Insertions
    list.push_back(10);
    list.push_back(30);
    cout << "Initial list:               ";
    list.print(); // Expected: [ 10 30 ]

    list.insert_at(1, 20); // Insert in the middle 
    cout << "After insert_at(1, 20):    ";
    list.print(); // Expected: [ 10 20 30 ]

    list.insert_at(0, 5);  // Insert at the beginning 
    cout << "After insert_at(0, 5):     ";
    list.print(); // Expected: [ 5 10 20 30 ]

    // 2. Test Search
    cout << "\n--- CONTAINS TEST ---" << endl;
    cout << "Is 20 in the list? " << (list.contains(20) ? "Yes" : "No") << endl; // Expected: Yes
    cout << "Is 99 in the list? " << (list.contains(99) ? "Yes" : "No") << endl; // Expected: No

    // 3. Test Deletion
    cout << "\n--- REMOVE AT TEST ---" << endl;
    int removed = list.remove_at(2); 
    cout << "Removed element at pos 2:  " << removed << endl;
    cout << "After remove_at(2):        ";
    list.print(); // Expected: [ 5 10 30 ]

    // Test Reversing the List
    cout << "\n--- REVERSE TEST ---" << endl;
    list.clear();
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    cout << "Before reverse: ";
    list.print(); // Expected: [ 1 2 3 4 ]

    list.reverse();

    cout << "After reverse:  ";
    list.print(); // Expected: [ 4 3 2 1 ]


    cout << "\n--- FINAL STATUS TEST ---" << endl;
    cout << "Current size: " << list.size() << endl;
    list.clear();
    cout << "After clear(), is empty?   " << (list.empty() ? "Yes" : "No") << endl;

    return 0;
}