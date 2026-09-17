class Book
{
private:
	int id;
	int category;
	bool borrow;
	
public:
    Book(int id, int category) : id(id), category(category), borrow(false)
    {
        
    }
    
    int getId()
    {
        return id;
    }
    
    bool getBorrowStatus()
    {
        return borrow;
    }
    
    void borrowBook()
    {
        borrow = true;
    }
    
    void returnBook()
    {
        borrow = false;
    }
};