#include <iostream>
using namespace std;

class Cars {
    public: 
    string brand;
    string model;
    int year;

    void display() {
        cout << endl << "----- Car Details -----" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int main(void) {
    Cars obj1;
    cout << "Enter the details of the First Car: " << endl;
    cout << "Enter Car Brand: ";
    cin >> obj1.brand;
    cout << "Enter Car Model: ";
    cin >> obj1.model;
    cout << "Enter Car Year: ";
    cin >> obj1.year;
    obj1.display();

}




