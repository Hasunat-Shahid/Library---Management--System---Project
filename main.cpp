#include<iostream>
using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    string yearPublished;
};

void addBook(vector<Book>&library) {
    Book newBook;
    cout<<"Enter title:";
    cin>>newBook.title;
    cout<<"Enter author:";
    cin>>newBook.author;
    cout<<"Enter ISBN:";
    cin>>newBook.ISBN;
    cout<<"Enter year published:";
    cin>>newBook.yearPublished
}


int main() {
    int choice;

    vector<Book>library;

    while(true) {
        cout<<"Library Management System\n";
        cout<<"1.Add a Book\n";
        cout<<"2.View All Books\n";
        cout<<"3.Search for a Book\n";
        cout<<"4.Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"Add a Book Selected\n";
            break;
            case 2:
            cout<<"View All Books Selected\n";
            break;
            case 3:
            cout<<"Search for a Book Selected\n";
            break;
            case 4:
            cout<<"Exiting program\n";
            break;
            default:
            cout<<"Invalid choice,try again\n";
        }
    }

Book myBook;
myBook.title="C++ Programming";
myBook.author="Bjarne Stroustrup";
myBook.ISBN="123_456789";
myBook.yearPublished="1985";

cout<<"Title:"<<myBook.title<<endl;
cout<<"Author:"<<myBook.author<<endl;
cout<<"ISBN:"<<myBook.ISBN<<endl;
cout<<"Year Published:"<<myBook.yearPublished<<endl;
}