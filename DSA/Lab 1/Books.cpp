#include <bits/stdc++.h>
using namespace std;

class Book
{
private:
    char *title;
    char *authors;
    int publishingYear;

public:
    // some method
    Book()
    {
        title = nullptr;
        authors = nullptr;
        publishingYear = 0;
    }
    Book(const char *title, const char *authors, int publishingYear)
    {
        string new_title(title);
        string new_authors(authors);
        this->title = new char[new_title.length() + 1];
        strcpy(this->title, new_title.c_str());
        this->authors = new char[new_authors.length() + 1];
        strcpy(this->authors, new_authors.c_str());
        this->publishingYear = publishingYear;
    }

    Book(const Book &book)
    {
        string new_title(book.title);
        string new_authors(book.authors);
        this->title = new char[new_title.length() + 1];
        strcpy(this->title, new_title.c_str());
        this->authors = new char[new_title.length() + 1];
        strcpy(this->authors, new_authors.c_str());
        this->publishingYear = book.publishingYear;
    }

    void setTitle(const char *title)
    {
        string new_title(title);
        delete this->title;
        this->title = new char[new_title.length() + 1];
        strcpy(this->title, new_title.c_str());
    }

    void setAuthors(const char *authors)
    {
        string new_authors(authors);
        delete this->authors;
        this->authors = new char[new_authors.length() + 1];
        strcpy(this->authors, new_authors.c_str());
    }

    void setPublishingYear(int publishingYear)
    {
        this->publishingYear = publishingYear;
    }
    char *getTitle() const
    {
        return this->title;
    }

    char *getAuthors() const
    {
        return this->authors;
    }

    int getPublishingYear() const
    {
        return this->publishingYear;
    }
    ~Book()
    {
        this->title = nullptr;
        this->authors = nullptr;
        this->publishingYear = 0;
    }

    void printBook()
    {
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};

int main()
{
    Book book1("Giai tich 1", "Nguyen Dinh Huy", 2000);
    Book book2 = book1;
    // book1.printBook();
    book2.printBook();
}