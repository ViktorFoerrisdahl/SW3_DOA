#include "Library.h"
#include <iostream>

void Library::addBook(int id, int category)
{
	if (category < 0 || category >= static_cast<int>(categories.size()))
		return;

	categories[category].emplace_back(id, category);
	totalBook++;

	int validCategories = 0;
	for (const auto& categoryBooks : categories){
		if (!categoryBooks.empty())
			validCategories++;
	}

	double averageBooks = static_cast<double>(totalBook) / validCategories;
	for (int currentCategory = 0; currentCategory < static_cast<int>(categories.size()); currentCategory++){
		if (!categories[currentCategory].empty() &&
			categories[currentCategory].size() > 2 * averageBooks)
			std::cout << "Warning: category " << currentCategory
			          << " contains more than twice the average number of books.\n";
	}
}


void Library::displayAllBooks()
{
	for (int category = 0; category < 16; category++){
		for (auto& book : categories[category]){
			std::cout << book.getId() << " in category: " << category << std::endl;
		}
	}
}

void Library::displayAvailableBooks()
{
	for (int category = 0; category < 16; category++){
		for (auto& book : categories[category]){
			if (!book.getBorrowStatus())
				std::cout << "\nAvailable books in the library:\n" << book.getId() << " in category: " << category << std::endl;
		}
	}
}

void Library::displayBorrowedBooks()
{
	for (int category = 0; category < 16; category++){
		for (auto& book : categories[category]){
			if (book.getBorrowStatus())
				std::cout << "\nBorrowed books in the library:\n" << book.getId() << " in category: " << category << std::endl;
		}
	}
}

bool Library::borrowBook(int id)
{
	for (auto& category : categories){
		for (auto& book : category){
			if (book.getId() == id && !book.getBorrowStatus())
			{
				book.borrowBook();
				return true;
			}
		}
	}
	return false;
}

bool Library::returnBook(int id)
{
	for (auto& category : categories){
		for (auto& book : category){
			if (book.getId() == id && book.getBorrowStatus())
			{
				book.returnBook();
				return true;
			}
		}
	}
	return false;
}

int Library::countBooksInCategory(int category) const
{
	if (category < 0 || category >= static_cast<int>(categories.size()))
		return 0;

	return static_cast<int>(categories[category].size());
}
