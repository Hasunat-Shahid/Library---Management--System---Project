#include<iostream>
using namespace std;

int main() {
    int choice;

    while(true) {
        cout<<"Library Management System\n";
        cout<<"1.Add a Book\n";
        cout<<"2.View All Books\n";
        cout<<"3.Search for a Book\n";
        cout<<"4.Exit\nw";
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
}