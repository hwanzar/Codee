#include <bits/stdc++.h>
using namespace std;

class Book{
private:
    char* title;
    char* authors;
    int publishingYear;
public:
    Book(){
        title = nullptr;
        authors = nullptr;
        publishingYear = 0;
    }

    Book(const char* title, const char* authors, int publishingYear){
        string new_title(title);
        string new_authors(authors);
        this->title = new char[new_title.length() + 1];
        this->authors = new char[new_authors.length() + 1];
        strcpy(this->title, new_title.c_str());
        strcpy(this->authors, new_authors.c_str());
        this->publishingYear = publishingYear;
    }

    ~Book(){
        this->title = nullptr;
        this->authors = nullptr;
    }

    friend class Printer;
};

class Printer{
public:
    static void printBook(const Book book){
        cout << book.title << '\n';
        string s(book.authors);
        for(unsigned i = 0; i < s.length(); i++){
            
        }
    }
};

int main(){

}