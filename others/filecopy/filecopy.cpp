// Write a C++ Program to Create a File 'People.dat' with name and age
// and to copy all the users available to vote 'Voters.dat' (above 18).
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class PEOPLE {
    private:
        char name[30];
        int age;
    public:
        PEOPLE(const char* n = "", int a = 0) : age(a) {
            strncpy(name, n, 30);
        }

        int get_age() const {
            return age;
        }
        void get_data() {
            cout << "Enter Name: ";
            cin.ignore();
            cin.getline(name, 30);
            cout << "Enter Age: ";
            cin >> age;
        }

        void put_data() {
            cout << name << " " << age << endl;
        }

        void create_file() {
            ofstream file("people.dat", ios::binary | ios::app);
            if (file.is_open()) {
                file.write(reinterpret_cast<char*>(this), sizeof(PEOPLE));
                file.close();
            } else {
                cout << "Error Opening File";
            }
        }
};

void transfer_data() {
            ifstream infile("people.dat", ios::binary);
            ofstream voters("voters.dat", ios::binary | ios::app);
            PEOPLE person;

            person.get_data();
            person.create_file();
            if (!(infile.is_open())) {
                cout << "Error Opening File";
            }
            if (infile.is_open()) {
                cout << "NAME\tAGE\n";
                while(infile.read(reinterpret_cast<char*>(&person), sizeof(PEOPLE))) {
                    person.put_data();
                }
                infile.close();
            } else {
                cout << "Error Opening File";
            }
            while (infile.read(reinterpret_cast<char*>(&person), sizeof(PEOPLE))) {
                if (person.get_age() > 18) {
                    voters.put_data();
                }
            }
            infile.close();
            voters.close();
        }

int main(void) {
    transfer_data();
    cout << "--- END ---";
}
