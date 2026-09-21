#include "set.h"
#include <cassert>
#include <iostream>
#include <string>

int main()
{
    set<int> a;
    a.addItem(1);
    a.addItem(1);
    a.removeItem(1);
    assert(!a.setContains(1)); // Duplicate was not inserted.
    a.removeItem(99);
    a.addItem(1);
    a.addItem(2);
    set<int> b;
    b.addItem(2);
    b.addItem(3);
    set<int> united = a.setUnion(b);
    assert(united.setContains(1));
    assert(united.setContains(2));
    assert(united.setContains(3));
    set<int> common = a.setIntersection(b);
    assert(!common.setContains(1));
    assert(common.setContains(2));
    assert(!common.setContains(3));
    set<int> difference = a.setDifference(b);
    assert(difference.setContains(1));
    assert(!difference.setContains(2));
    assert(!difference.setContains(3));
    assert(a.setContains(1) && a.setContains(2));
    assert(b.setContains(2) && b.setContains(3));
    set<int> same = a.setIntersection(a);
    assert(same.setContains(1) && same.setContains(2));
    set<int> none = a.setDifference(a);
    assert(!none.setContains(1) && !none.setContains(2));
    set<std::string> words;
    words.addItem("apple");
    words.addItem("pear");
    set<std::string> sameWords = words.setIntersection(words);
    assert(sameWords.setContains("apple"));
    assert(sameWords.setContains("pear"));
    std::cout << "Set tests passed!\n";
}
