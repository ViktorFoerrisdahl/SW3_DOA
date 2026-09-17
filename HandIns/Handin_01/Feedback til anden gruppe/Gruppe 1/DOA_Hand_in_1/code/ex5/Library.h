#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#include "Book.h"
#include <array>
#include <list>


class Library
{
private:
	std::array<std::list<Book>, 16> categories;
    int totalBook = 0;

public:
	void addBook(int id, int category);
	void displayAllBooks();
	void displayAvailableBooks();
	void displayBorrowedBooks();
	bool borrowBook(int id);
	bool returnBook(int id);
	int countBooksInCategory(int category) const;
};

#endif
	

