#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Book {
private:
    int id;
    int category;
    bool borrowed;

public:
    Book(int id, int category) : id(id), category(category), borrowed(false) {}

    int getId() const { return id; }
    int getCategory() const { return category; }
    bool isBorrowed() const { return borrowed; }

    void setBorrowed(bool status) { borrowed = status; }

    void display() const {
        cout << "Book ID: " << id 
            << "\nCategory: " << category 
            << "\nStatus: " << (borrowed ? "Borrowed" : "Available") 
            << endl;
    }
};

class Library {
private:
    vector<Book> books;
    vector<int> categoryCount = vector<int>(16, 0); // Vector of size 16 initialized to 0
public:
    void addBook(int id, int category) {
    
        // Check category validity
        if (category < 0 || category > 15) {
            cout << "Invalid category\n";
            return;
        }

        // Go through books to check if ID matches book already
        for (const auto& b : books) {
            if (b.getId() == id) {
                cout << "Book is already in library\n";
                return;
            }
        }

        // Add book to vector and update category count
        books.push_back(Book(id, category));
        categoryCount[category]++;

        // Warning fragment if category exceeds given limit
        if (!books.empty()) {

            // Check number of categories with books in them
            int validCategories = 0;
            for (int i = 0; i < 16; i++) {
                if (categoryCount[i] > 0) {
                    validCategories++;
                }
            }

            if (validCategories > 0) {
                double currentAverage = static_cast<double>(books.size()) / validCategories;
                // Issue warning if category exceeds limit
                if ((categoryCount[category] + 1) > 2.0 * currentAverage) {
                    cout << "Warning: Adding Book exceeds category limit" << endl;
                }
            }
        }
    }

    bool borrowBook(int id) {
        // Go through books to check if it is there
        for (auto& b : books) {
            if (b.getId() == id) {
                // If book is found, check if it is borrowed
                if (!b.isBorrowed()) {
                    // Book is not borrowed
                    // Update to book being borrowed and return true
                    b.setBorrowed(true);
                    return true;
                }
                // Book was found but is already borrowed
                return false;
            }
        }
        // Book was not found in the library
        return false;
    }

    bool returnBook(int id) {
        // Go through books to check if it is there
        for (auto& b : books) {
            if (b.getId() == id) {
                // If book is found and borrowed update status to not borrowed and return true
                if (b.isBorrowed()) {
                    b.setBorrowed(false);
                    return true;
                }
                // Book was found but is not set as borrowed
                return false;
            }
        }
        // Book was not found in the library
        return false;
    }

    void displayAllBooks() const {
        // Go through all books and display them one by one
        for (const auto& b : books) {
            b.display();
        }
    }

    void displayAvailableBooks() const {
        // Go through all books and display the ones that aren´t borrowed
        for (const auto& b : books) {
            if (!b.isBorrowed()) {
                b.display();
            }
        }
    }

    void displayBorrowedBooks() const {
        // Go through all books and display the ones that are borrowed
        for (const auto& b : books) {
            if (b.isBorrowed()) {
                b.display();
            }
        }
    }

    int countBooksInCategory(int category) const {
        // Check if category is valid (0-15)
        if (category >= 0 && category <= 15) {
            return categoryCount[category]; // Return number of books in the category
        }
        return 0;
    }
};

int main() {
    Library myLibrary;

    // Adding books to the library
    myLibrary.addBook(1, 3);
    myLibrary.addBook(2, 7);
    myLibrary.addBook(3, 3);
    myLibrary.addBook(4, 15);
    myLibrary.addBook(5, 3);
    myLibrary.addBook(6, 0);

    // Display all books in the library
    cout << "\nAll books in the library:\n";
    myLibrary.displayAllBooks();

    // Display available books
    cout << "\nAvailable books in the library:\n";
    myLibrary.displayAvailableBooks();

    // Borrow a book by ID
    cout << "\nBorrowing Book ID 2:\n";
    if (myLibrary.borrowBook(2)) {
        cout << "Book ID 2 borrowed successfully.\n";
    } else {
        cout << "Failed to borrow Book ID 2.\n";
    }

    // Attempt to borrow the same book again
    cout << "\nAttempting to borrow Book ID 2 again:\n";
    if (myLibrary.borrowBook(2)) {
        cout << "Book ID 2 borrowed successfully.\n";
    } else {
        cout << "Failed to borrow Book ID 2.\n";
    }

    // Display borrowed books
    cout << "\nBorrowed books in the library:\n";
    myLibrary.displayBorrowedBooks();

    // Return a borrowed book by ID
    cout << "\nReturning Book ID 2:\n";
    if (myLibrary.returnBook(2)) {
        cout << "Book ID 2 returned successfully\n";
    } else {
        cout << "Failed to return Book ID 2\n";
    }

    // Display available books after returning
    cout << "\nAvailable books in the library after returning Book ID 2:\n";
    myLibrary.displayAvailableBooks();

    // Display the number of books in a specific category
    int categoryToCheck = 3;
    cout << "\nNumber of books in category " << categoryToCheck << ": "
         << myLibrary.countBooksInCategory(categoryToCheck) << endl;
    
    return 0;
}