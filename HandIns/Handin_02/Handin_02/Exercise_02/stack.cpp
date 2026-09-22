#include "stack.h"

stack::stack(int size) : size_(size), head_(0)
{
    array_ = new int[size_]{};
}

stack::~stack()
{
    delete[] array_;
}

void stack::pop()
{
    array_[head_] = 0;
    head_--;
}

void stack::push(int x)
{
    if (head_ == size_)
    {
        int *new_array_ = new int[size_ * 2];
        for (auto i = 0; i < size_; i++)
        {
            new_array_[i] = array_[i];
        }
        size_ *= 2;
        delete[] array_;
        array_ = new_array_;
        array_[head_++] = x;
    }
    array_[head_++] = x;
}