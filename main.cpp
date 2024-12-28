#include<iostream>
#include<vector>
#include<fstream>
#include<limits>
using namespace std;

// Struct to store book information
struct Book {
    string title;
    string author;
    string ISBN;
    int yearPublished;
};

// Function to add a new book with year validation
void addBookWithValidation(vector<Book>& library) {
    Book newBook;  // Create a new book object

    // Get book details from the user
    cout << "Enter title: ";
    cin.ignore();  
    getline(cin, newBook.title);  
    cout << "Enter author: ";
    getline(cin, newBook.author);  
    cout << "Enter ISBN: ";
    cin >> newBook.ISBN;

    // Validate year input
    cout << "Enter year: ";
    while (true) {
        cin >> newBook.yearPublished;
        if (cin.fail()) {  
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid year, please enter a valid integer: ";
        } else {
            break;
        }
    }
    
    // Add the book to the library
    library.push_back(newBook);
    cout << "Book added successfully!" << endl;
}

// Function to display all books in the library
void viewBooks(const vector<Book>& library) {
    for (const Book& book : library) {
        cout << "Title: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "ISBN: " << book.ISBN << endl;
        cout << "Year Published: " << book.yearPublished << endl;
        cout << "------------------------" << endl;
    }
}

// Function to search for a book by title
void searchBookByTitle(const vector<Book>& library, const string& title) {
    bool found = false;
    for (const Book& book : library) {
        if (book.title == title) {
            cout << "Book found: " << book.title << " by " << book.author << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No book found with title: " << title << endl;
    }
}

int main() {
    int choice;
    vector<Book> library;

    while (true) {
        // Display menu options
        cout << "Library Management System\n";
        cout << "1. Add a Book\n";
        cout << "2. View All Books\n";
        cout << "3. Search for a Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform action based on user choice
        switch (choice) {
            case 1:
                addBookWithValidation(library);  
                break;
            case 2:
                viewBooks(library);  
                break;
            case 3:
                {
                    string searchTitle;
                    cout << "Enter title to search: ";
                    cin >> searchTitle;
                    searchBookByTitle(library, searchTitle);  
                }
                break;
            case 4:
                cout << "Exiting program\n";
                return 0;  
            default:
                cout << "Invalid choice, try again\n";
        }
    }

    return 0;  
}
