										/* Library Book Management System */
										
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
    float price;
    int serialNumber;

public:
    Book(string title, string author, int year, float price, int serialNumber) {
        this->title = title;
        this->author = author;
        this->year = year;
        this->price = price;
        this->serialNumber = serialNumber;
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << endl;
        cout << "Serial Number: " << serialNumber << endl;
        cout << "----------------------" << endl;
    }

    bool matchTitle(string query) {
        return title.find(query) != string::npos;
    }

    bool matchAuthor(string query) {
        return author.find(query) != string::npos;
    }

    bool matchYear(int query) {
        return year == query;
    }

    bool matchPrice(float query) {
        return price == query;
    }

    bool matchSerialNumber(int query) {
        return serialNumber == query;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(Book book) {
        books.push_back(book);
        cout << "Book added to the library." << endl;
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "Library is empty. No books to display." << endl;
        } else {
            cout << "Books in the library:" << endl;
            for (int i = 0; i < books.size(); i++) {
                books[i].display();
            }
        }
    }

    void searchBooks() {
        if (books.empty()) {
            cout << "Library is empty. No books to search." << endl;
        } else {
            string query;
            int choice;

            cout << "Search Options:" << endl;
            cout << "1. Title" << endl;
            cout << "2. Author" << endl;
            cout << "3. Year" << endl;
            cout << "4. Price" << endl;
            cout << "5. Serial Number" << endl;
            cout << "Enter your choice (1-5): ";
            cin >> choice;

            cout << "Enter the search query: ";
            cin.ignore();
            getline(cin, query);

            cout << "Matching books:" << endl;
            for (int i = 0; i < books.size(); i++) {
                bool isMatch = false;

                switch (choice) {
                    case 1:
                        isMatch = books[i].matchTitle(query);
                        break;
                    case 2:
                        isMatch = books[i].matchAuthor(query);
                        break;
                    case 3:
                        isMatch = books[i].matchYear(atoi(query.c_str()));
                        break;
                    case 4:
                        isMatch = books[i].matchPrice(static_cast<float>(atof(query.c_str())));
                        break;
                    case 5:
                        isMatch = books[i].matchSerialNumber(atoi(query.c_str()));
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        return;
                }

                if (isMatch) {
                    books[i].display();
                }
            }
        }
    }
};

int main() {
    int numBooks;
    cout << "Enter the number of books: ";
    cin >> numBooks;

    Library library;

    for (int i = 0; i < numBooks; i++) {
        string title, author;
        int year, serialNumber;
        float price;

        cout << "Enter details for Book " << i + 1 << ":" << endl;
        cout << "Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Author: ";
        getline(cin, author);
        cout << "Year: ";
        cin >> year;
        cout << "Price: ";
        cin >> price;
        cout << "Serial Number: ";
        cin >> serialNumber;

        Book book(title, author, year, price, serialNumber);
        library.addBook(book);
    }

    library.displayBooks();
    library.searchBooks();

    return 0;
}

