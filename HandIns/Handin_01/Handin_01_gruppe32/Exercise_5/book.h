#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>

class Book {

    friend std::ostream &operator<<(std::ostream&, const Book&);

    private:
    int id_;
    int category_;
    bool borrowed_ = false;

    public:
    Book(int id, int category);
    int getId() const;
    int getCategory() const;
    bool getStatus() const;
    void updateStatus(bool borrowed);
};



#endif