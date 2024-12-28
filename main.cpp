#include<iostream>
#include<vector>
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
    cin>>newBook.yearPublished;

    library.push_back(newBook);
}

void  viewBooks(const vector<Book>& library) {
    for (const Book& book : library) {
        cout<<"Title:"<<book.title<<endl;
        cout<<"Author:"<<book.author<<endl;
        cout<<"ISBN:"<<book.yearPublished<<endl;
        cout<<"------------------------"<<endl;
    }
}

void searchBookByTitle(const vector<Book>&library, const string& title){
    bool found=false;
    for(const Book&book:library){
        if(book.title==title){
            cout<<"Book found:"<<book.title<<"by"<<book.author<<endl;
            found=true;
            break;
        }
    }
    if(!found){
        cout<<"No book found with title:"<<title<<endl;
    }
}

void saveBooksToFile(const vector<Book>&library){
    ofstream file("library.txt");
    for(const Book&book:library){
        file<<book.title<<","<<book.author<<","<<book.ISBN<<","<<book.yearPublished<<endl;
    }
    file.close();
}

void loadBooksFromFile(vector<Book>&library){
    ifstream file("library.txt");
    Book book;
    while(file>>book.title>>book.author>>book.ISBN>>book.yearPublished){
        library.push_back(book);
    }
    file.close();
}

 void deleteBook(vector<Book>&library,const string& title){
      for(auto it=library.begin();it!=library.end();++it){
          if(it->title==title){
              libray.erase(it);
              cout<<"Book deleted successfully."<<endl;
              return;
          }
      }
      cout<<"Book not found"<<endl;
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

        if(choice=1){
            addBook(library);
        }
        else if(choice==2){
            viewBooks(library);
        }
        else if(choice==3){
            break;
        }
        else{
            cout<<"Invalid choice, try again."<<endl;
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