#include "book.h"

Book::Book(int id, int category) : id_(id), category_(category) {}

int Book::getId() const
{
    return id_;
}

int Book::getCategory() const
{
    return category_;
}

bool Book::getStatus() const 
{
    return borrowed_;
}

void Book::updateStatus(bool borrowed)
{
    borrowed_ = borrowed;
}

std::ostream &operator<<(std::ostream& os, const Book &b)
{
    os << "Id: " << b.getId() << ", " << "Category: " << b.getCategory() << std::endl;
    return os;
}
