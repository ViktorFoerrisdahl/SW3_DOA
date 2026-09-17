#include "library.h"

Library::Library() {}

void Library::addBook(int id, int category)
{
    if (valid_categories_ > 0)
    {
        if (((static_cast<float>(books_.size()) / valid_categories_) * 2) < categories_[category] + 1)
        {
            std::cout << "\n"
                      << "Warning! Category " << category << " exceeds twice the average number of books per valid category.\n";
        }
    }

    if (categories_[category] == 0)
    {
        valid_categories_++;
    }

    categories_[category]++;

    books_.push_back(Book(id, category));
}

void Library::displayAllBooks()
{
    for (const auto &i : books_)
    {
        std::cout << i;
    }
}

void Library::displayAvailableBooks()
{
    for (const auto &i : books_)
    {
        if (!i.getStatus())
        {
            std::cout << i;
        }
    }
}

void Library::displayBorrowedBooks()
{
    for (const auto &i : books_)
    {
        if (i.getStatus())
        {
            std::cout << i;
        }
    }
}

Borrowed_Status Library::borrowBook(int id)
{
    if (books_[id - 1].getStatus() == false)
    {
        books_[id - 1].updateStatus(true);
        return Borrowed_Succes;
    }
    else
    {
        return Borrowed_Not_succes;
    }
}

Return_Status Library::returnBook(int id)
{
    if (books_[id - 1].getStatus() == true)
    {
        books_[id - 1].updateStatus(false);
        return Return_Succes;
    }
    else
    {
        return Return_Not_succes;
    }
}

int Library::countBooksInCategory(int category)
{
    return categories_[category];
}
