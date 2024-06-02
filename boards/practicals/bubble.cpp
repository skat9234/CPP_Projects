// Define a class named BUBBLE consisting of the following members:
//  i) list: an array of type short integer of size 30 under private visibility label.
//  ii) N : of type short unsigned integer(indicates total number of elements to be
//      accepted in array “list”)under private visibility label.
//  iii) Define a default constructor to accept data member “N” and to accept the
//      numbers in the array “list” .It further calls member function “sort” followed by
//      member function “show”.
//  iv) Define a private member function named “sort” which performs sorting of
//      numbers in array “list” using bubble sort technique(sort in ASCENDING
//      order).
//  v) Define a private member function named “show” which displays the content of
//      array
// Write a relevant main function to complete the Program

#include <iostream>
using namespace std;

class BUBBLE {
    private:
        short int list[30]; // Array to store the numbers
        short unsigned int N; // Number of elements in the array

        void sort() {
            for (int i=0; i<N-1; ++i) { // Iterate through the array
                for (int j=0; j<N-i-1; ++j) { // Compare adjacent elements
                    if (list[j] > list[j+1]) { // Swap if the current element is greater than the next element
                        short int temp = list[j];
                        list[j] = list[j+1];
                        list[j+1] = temp;
                    }
                }
            }
        }

        void show() {
            cout << "Sorted Array: ";
            for (int i=0; i<N; ++i) { // Iterate through the array
                cout << list[i] << " "; // Print each element
            }
            cout << endl;
        }

    public:
        BUBBLE(short unsigned int num) : N(num) {
            cout << "Enter " << N << " numbers of the array: " << endl; // Prompt the user to enter the numbers
            for (int i=0; i<N; ++i) { // Iterate through the array
                cin >> list[i]; // Read each element from the user
            }
            
            sort(); // Sort the array
            show(); // Display the sorted array
        }

};

int main(void) {
    short unsigned int totalElements;
    cout << "Enter Total Number of Elements (<=30): ";
    cin >> totalElements;
    BUBBLE bubbleObj(totalElements);
}