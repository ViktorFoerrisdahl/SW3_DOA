#include "queue.h"
#include <cassert>
#include <iostream>
#include <string>

int main()
{
    queue<int> q;
    bool thrown = false;
    try { q.popQueue(); }
    catch (const std::runtime_error&) { thrown = true; }
    assert(thrown);
    thrown = false;
    try { q.firstInQueue(); }
    catch (const std::runtime_error&) { thrown = true; }
    assert(thrown);
    q.pushQueue(10);
    q.pushQueue(20);
    assert(q.firstInQueue() == 10);
    assert(q.firstInQueue() == 10);
    q.popQueue();
    q.pushQueue(30);
    assert(q.firstInQueue() == 20);
    q.popQueue();
    assert(q.firstInQueue() == 30);
    q.popQueue();
    queue<std::string> words;
    words.pushQueue("hello");
    assert(words.firstInQueue() == "hello");
    words.popQueue();
    std::cout << "Queue tests passed!\n";
}
