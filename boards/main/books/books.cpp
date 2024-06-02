#include <iostream>
#include <fstream>
using namespace std;

class BOOK {
    public:
        long int bid;
        char title[40];
        char author[40];
        float price;
        char type;
};

int main(void) {
    int n;
    BOOK book;
    cout << "Enter No. of Books: ";
    cin >> n;

    ofstream file("LIBBOOK.dat", ios::binary);
    if (!file) {
        cout << "Error Creating File";
        return 1;
    }

    for (int i=0; i<n; i++) {
        cout << "Details for Book-" << i+1 << ": " << endl;
        cout << "Enter Book ID: ";
        cin >> book.bid;

        cout << "Enter Title: ";
        cin.ignore(); // Add this line to ignore the newline character
        cin.getline(book.title, 40);
        
        cout << "Enter Author: ";
        cin.getline(book.author, 40);

        cout << "Enter Price: ";
        cin >> book.price;

        cout << "Enter Type: ";
        cin >> book.type;

        file.write(reinterpret_cast<char*>(&book), sizeof(book));   
    } 
    file.close();

    ifstream readFile("LIBBOOK.dat", ios::binary); // Replace ofstream with ifstream

    if (!readFile) { // Replace 'readFile' with 'file'
        cout << "Error Opening File";
    }
    while(readFile.read(reinterpret_cast<char*>(&book), sizeof(book))) { // Replace 'readFile' with 'file'
        if (book.type == 'A') { // Replace double quotes with single quotes
            cout << book.bid;
            cout << book.title;
            cout << book.author;
            cout << book.price;
            cout << book.type;
        }
    }
    readFile.close(); // Replace 'file' with 'readFile'
    if (!readFile) {
        cout << "Error Opening File";
    }
    while(readFile.read(reinterpret_cast<char*>(&book), sizeof(book))) {
        if (book.type == 'A') {
            cout << book.bid;
            cout << book.title;
            cout << book.author;
            cout << book.price;
            cout << book.type;
        }
    }
    file.close();

}