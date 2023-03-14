#include <iostream>
#include <string>
#include <map>

using namespace std;

class Book {
public:
    string author;
    string title;
    int year;
    
    Book(string author, string title, int year) {
        this->author = author;
        this->title = title;
        this->year = year;
    }
};

class Library {
private:
    multimap<string, Book> books;
    
public:
    void addBook(string author, string title, int year) {
        Book book(author, title, year);
        books.insert(make_pair(author, book));
        cout << "Book added: " << author << ", " << title << ", " << year << endl;
    }
    
    void removeBook(string author, string title) {
        multimap<string, Book>::iterator it = books.find(author);
        while (it != books.end() && it->first == author) {
            if (it->second.title == title) {
                cout << "Book removed: " << author << ", " << title << endl;
                books.erase(it++);
            }
            else {
                ++it;
            }
        }
    }
    
    void searchAuthor(string author) {
        multimap<string, Book>::iterator it = books.find(author);
        if (it != books.end()) {
            cout << "Books by " << author << ":" << endl;
            while (it != books.end() && it->first == author) {
                cout << "- " << it->second.title << " (" << it->second.year << ")" << endl;
                ++it;
            }
        }
        else {
            cout << "No books found for author " << author << endl;
        }
    }
    
    void searchYear(int year) {
        bool found = false;
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->second.year == year) {
                if (!found) {
                    cout << "Books published in " << year << ":" << endl;
                    found = true;
                }
                cout << "- " << it->second.title << " by " << it->second.author << endl;
            }
        }
        if (!found) {
            cout << "No books found for year " << year << endl;
        }
    }
};

int main() {
    Library library;
    library.addBook("J.K. Rowling", "Harry Potter and the Philosopher's Stone", 1997);
    library.addBook("J.K. Rowling", "Harry Potter and the Chamber of Secrets", 1998);
    library.addBook("J.K. Rowling", "Harry Potter and the Prisoner of Azkaban", 1999);
    library.addBook("George R.R. Martin", "A Game of Thrones", 1996);
    library.searchAuthor("J.K. Rowling");
    library.searchYear(1996);
    library.removeBook("J.K. Rowling", "Harry Potter and the Chamber of Secrets");
    library.searchAuthor("J.K. Rowling");
    return 0;
}
