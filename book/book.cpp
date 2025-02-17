#include <iostream>
#include <string>
#include <exception>
#include <cstring>

typedef char *String;
typedef enum
{
    TRUE = 1,
    FALSE = 0
} Boolean;

class Book
{
protected:
    String book_name;
    int catalog_number;

public:
    Book();
    ~Book();

    void set_catalog_number(int num);
    int get_catalog_number() const;

    void set_book_name(const String name); // ✅ קבלת `const char*` למניעת השגיאה
    String get_book_name() const;
    Boolean book_name_is_set() const;

    virtual Book &operator=(const Book &) = 0;
};


Book::Book() { book_name = NULL; };
Book::~Book() { delete[] book_name; }

void Book::set_catalog_number(int num) { catalog_number = num; }

int Book::get_catalog_number() const { return catalog_number; }

void Book::set_book_name(const String name) // ✅ שימוש ב-`const char*`
{
    if (book_name != NULL)
        delete[] book_name;
    book_name = new char[strlen(name) + 1];
    strcpy(book_name, name);
}
String Book::get_book_name() const
{

    char *tmp = new char[strlen(book_name) + 1];
    return strcpy(tmp, book_name);
}
Boolean Book::book_name_is_set() const
{
    if (book_name != NULL)
        return TRUE;
    return FALSE;
}

class Reserved_Book : public Book
{
    int fine;
    public:
        Reserved_Book() : fine(0){};
        Reserved_Book(const Reserved_Book & rBook) //copy constructor
        {
            this->fine = rBook.fine;
            book_name = rBook.book_name;
            catalog_number = rBook.catalog_number;
        }

        Book &operator=(const Book &){
            return *this;
        }

        Reserved_Book &operator=(const Reserved_Book &);

        int getFine()const {return fine;};
        void setFine(int fine){this->fine = fine;};

        void print(){
            std::cout << "name: " << (book_name ? book_name : "No Name") << std::endl;
            std::cout << "number: " << catalog_number << std::endl;
            std::cout << "fine: " << fine << std::endl;
        }
};
Reserved_Book &Reserved_Book::operator=(const Reserved_Book &rBook)
{
    if (this != &rBook) // הגנה מהשמה עצמית
    {
        fine = rBook.getFine();
        set_book_name(rBook.book_name);
        catalog_number = rBook.catalog_number;
    }
    return *this;
}

int main()
{
    Reserved_Book b;

    b.set_book_name("OOP");
    b.set_catalog_number(17);
    b.setFine(7);
    
    Reserved_Book a = b;
    a.set_book_name("C++");

    a.print();
    b.print();

    return 0;
}
