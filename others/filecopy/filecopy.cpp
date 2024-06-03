// Write a C++ Program to Store a list of People and transfer all 
// off them above 18 to another list of Voters.dat

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class PEOPLE {
    private:
        char name[30];
        int age;
    
    public:
        PEOPLE(const char* n="", int a=0) : age(a) {
            strncpy(name, n, 30);
        } 

        int get_age() {
            return age;
        }

        void write_to_file(ofstream &file) {
            file.write(reinterpret_cast<char*>(this), sizeof(PEOPLE));
        }

        void read_from_file(ifstream &file) {
            file.read(reinterpret_cast<char*>(this), sizeof(PEOPLE));
        }
        void display() const {
            cout << "Name: " << name << ", Age: " << age << endl;
        }
};

void SegregateVoters() {
    ifstream mainfile("people.dat", ios::binary);
    if (!mainfile) {
        cerr << "Error Opening File";
        return;
    }

    ofstream voter("voters.dat", ios::binary | ios::app);
    if (!voter) {
        cerr << "Error Opening File";
        return;
    }

    PEOPLE person;

    while(mainfile.read(reinterpret_cast<char*>(&person), sizeof(PEOPLE))) {
        if (person.get_age() >= 18) {
            person.write_to_file(voter);
        }
    }

    mainfile.close();

}

int main(void) {
    int numPeople;

    ofstream outmain("people.dat", ios::binary | ios::app);
    if (!outmain) {
        cerr << "Error Opening File";
        return 1;
    }

    cout << "Enter number of people: ";
    cin >> numPeople;

    for (int i=0; i<numPeople; i++) {
        char name[30];
        int age;

        cout << "Enter Details for Person-" << i+1 << ": "<< endl;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 30);
        cout << "Enter Age: ";
        cin >> age;

        PEOPLE person(name, age);
        person.write_to_file(outmain);
    } 
    outmain.close();
    cout << "Data Input to people.dat Successful" << endl;

    cout << endl << "Tranferring Filtered Data to voters.dat ... " << endl;
    SegregateVoters();

    PEOPLE person;
    ifstream voter("voters.dat", ios::binary);
    while (voter.read(reinterpret_cast<char*>(&person), sizeof(PEOPLE))) {
        person.display();
    }

}
