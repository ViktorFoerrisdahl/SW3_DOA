#ifndef STACK_H
#define STACK_H

class stack
{
public:
    stack(int size = 100); //constructor
    ~stack(); //destructor
 
    void pop();
    void push(int x);
    int size() const { return head_; }
    int sizeOfStack() const { return size_; }
    int top() const;

private:
    int size_;
    int head_;
    int *array_;
};

#endif