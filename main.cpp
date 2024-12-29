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
void addBookWithValidation(vector<Book>& library);

void saveBookToFile(const vector<Book>& library) {
    ofstream file("library.txt");  // Declare the ofstream object

    if (!file) {  // Check if the file opened successfully
        cout << "Error opening file for writing!" << endl;
        return;
    }

    // Write each book to the file
    for (const Book& book : library) {
        file << book.title << "," << book.author << "," << book.ISBN << "," << book.yearPublished << endl;
    }

    file.close();  // Close the file
}

void deleteBook(vector<Book>& library, const string& title) {
    for (auto it = library.begin(); it != library.end(); ++it) {
        if (it->title == title) {
            library.erase(it);
            cout << "Book deleted successfully." << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
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

// Function to add a new book with validation
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

    // Save the updated list of books to file
    saveBookToFile(library);  // Automatically call saveBookToFile when a book is added
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
        cout << "4. Delete a Book\n";
        cout << "5. Exit\n";
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
                    cin.ignore();  // To avoid leftover newline character
                    getline(cin, searchTitle);
                    searchBookByTitle(library, searchTitle);  
                }
                break;
            case 4:
                {
                    string deleteTitle;
                    cout << "Enter title of the book to delete: ";
                    cin.ignore();  
                    getline(cin, deleteTitle);
                    deleteBook(library, deleteTitle); 
                    break;
                }
            case 5:
                cout << "Exiting program\n";
                return 0;  
            default:
                cout << "Invalid choice, try again\n";
        }
    }

    return 0;  
}
