#ifndef LIBRARY_H
#define LIBRARY_H
#include "book.h"
#include <string>
#include <array>
#include <vector>
#include <iostream>
#include <ostream>

enum Borrowed_Status
{
    Borrowed_Succes = true,
    Borrowed_Not_succes = false
};

enum Return_Status
{
    Return_Succes = true,
    Return_Not_succes = false
};

class Library
{

private:
    std::vector<Book> books_;
    std::array<int, 16> categories_{};
    int valid_categories_ = 0;

public:
    Library();
    void addBook(int id, int category);
    void displayAllBooks();
    void displayAvailableBooks();
    void displayBorrowedBooks();
    Borrowed_Status borrowBook(int id);
    Return_Status returnBook(int id);
    int countBooksInCategory(int category);
};

#endif