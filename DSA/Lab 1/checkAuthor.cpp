#include <bits/stdc++.h>
using namespace std;

class Book
{
private:
    char *title;
    char *authors;
    int publishingYear;

public:
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
    ~Book()
    {
        this->title = nullptr;
        this->authors = nullptr;
    }

    friend bool checkAuthor(Book book, const char *author)
    {
        if (book.authors == nullptr || author == nullptr)
            return false;
        string s1(book.authors);
        string s2(author);
        s1.insert(0, ", ");
        s2.insert(0, ", ");
        s1 += ',';
        s2 += ',';
        size_t found = s1.find(s2);
        if (found == string::npos)
            return false;
        return true;
    }
};

int main()
{
    Book book1("Giai tich 1", "Nguyen Dinh Huy, Nguyen Thi Xuan Anh", 2000);
    cout << checkAuthor(book1, "Nguyen Dinh Huy");
}