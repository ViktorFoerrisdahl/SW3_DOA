#include "stack.h"
#include <stdexcept>

stack::stack(int size) : size_(size), head_(0)
{
    if (size_ <= 0)
        throw std::invalid_argument("Capacity must be positive");
    array_ = new int[size_]{};
}

stack::~stack()
{
    delete[] array_;
}

void stack::pop()
{
    if (head_ == 0)
        throw std::out_of_range("Cannot pop from an empty stack");
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
    }
    array_[head_++] = x;
}

int stack::top() const
{
    if (head_ == 0)
        throw std::out_of_range("Stack is empty");
    return array_[head_ - 1];
}
