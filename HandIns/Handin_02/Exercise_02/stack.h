#ifndef STACK_H
#define STACK_H

class stack
{
public:
    stack(int size = 100); //constructor
    ~stack(); //destructor
 
    void pop();
    void push(int x);

private:
    int size_;
    int head_;
    int *array_;
};

#endif