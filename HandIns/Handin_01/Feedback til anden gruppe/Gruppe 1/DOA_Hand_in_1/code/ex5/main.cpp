#include <iostream>
#include "Library.h"
using namespace std;

int main() {
	Library library;
	// Adding books to the library
	library.addBook(1, 3);
	library.addBook(2, 7);
	library.addBook(3, 3);
	library.addBook(4, 15);
	library.addBook(5, 3);
	library.addBook(6, 0);
	library.addBook(7, 3);  // Deliberately triggers the balance warning.
	// Display all books in the library
	std :: cout << "\nAll books in the library:\n";
	library.displayAllBooks();
	// Display available books
	std :: cout << "\nAvailable books in the library:\n";
	library.displayAvailableBooks();
	// Borrow a book by ID
	std :: cout << "\nBorrowing Book ID 2:\n";
	if (library.borrowBook(2)) {
		std :: cout << "Book ID 2 borrowed successfully.\n";
	} else {
		std :: cout << "Failed to borrow Book ID 2.\n";
	}
	// Attempt to borrow the same book again
	std :: cout << "\nAttempting to borrow Book ID 2 again:\n";
	if (library.borrowBook(2)) {
		std :: cout << "Book ID 2 borrowed successfully.\n";
	} else {
		std :: cout << "Failed to borrow Book ID 2.\n";
	}
	// Display borrowed books
	std :: cout << "\nBorrowed books in the library:\n";
	library.displayBorrowedBooks();
	// Return a borrowed book by ID
	std :: cout << "\nReturning Book ID 2:\n";
	if (library.returnBook(2)) {
		std :: cout << "Book ID 2 returned successfully.\n";
	} else {
		std :: cout << "Failed to return Book ID 2.\n";
	}
	// Display available books after returning
	std :: cout << "\nAvailable books in the library after returning Book ID 2:\n";
	library.displayAvailableBooks();
	// Display the number of books in a specific category
	int categoryToCheck = 3;
	std :: cout << "\nNumber of books in category " << categoryToCheck << ": "
	            << library.countBooksInCategory(categoryToCheck) << std :: endl ;
	return 0;
}