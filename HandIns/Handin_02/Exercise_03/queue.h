#ifndef QUEUE_H
#define QUEUE_H
#include <stack>
#include <stdexcept>

template <typename T>
class queue
{
private:
    std::stack<T> s1;  // To stacks oprettes for at kunne omdanne LIFO til FIFO
    std::stack<T> s2;

public:
    void pushQueue(T x)
    {
        s1.push(x);  // Værdier bliver tilføjet til en stack 
    }



    /* 
    While løkke laves hvor indlæste værdier rykkes fra den først stack til den anden stack
    for at vende rækkefølgen om og værdierne kan aflæses/fjernes som FIFO i stedet for LIFO 
    */
    void popQueue()
    {
        while (!s1.empty())   // Vender stacken om
        {
            T x = s1.top();
            s1.pop();
            s2.push(x);
        }
        if (s2.empty())   // tjek om stack er tom før der fjernes noget fra stackken
        {
            throw std::runtime_error("Queue is empty"); 
        }
        s2.pop();   // Fjerne første ting fra stacken

        while (!s2.empty()) // Vender stacken om
        {
            T x = s2.top();
            s2.pop();
            s1.push(x);
        }
    }



    T firstInQueue()    // Laves af samme grund som popQueue 
    {
        T first;  // Instalisere en standard værdi til at indehold første værdi
        while (!s1.empty())
        {
            T x = s1.top();
            s1.pop();
            s2.push(x);
        }
        if (s2.empty())
        {
            throw std::runtime_error("Queue is empty");
        }
        first = s2.top();

        while (!s2.empty())
        {
            T x = s2.top();
            s2.pop();
            s1.push(x);
        }
        return first;  // Retunere den første tilføjet værdi til stacken
    }
};

#endif