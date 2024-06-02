// Define a class named SELECT consisting of the following members:
//  i) list: an array of type short integer of size 30 under private.
//  ii) N :of type short unsigned integer.(indicates total number of elements to
//      be accepted in array “list” ) under private.
//  iii) Define a default constructor to accept data member “N” and to accept the
//      numbers in the array “list”. It further calls member function “sort” followed by
//      member function “show”.
//  iv) Define a private member function named “sort” which performs sorting of
//      numbers in the array “list” using selection sort technique (sort in ASCENDING
//      order).
//  v) Define a private member function named “show” which displays the content of
//      array.
// Write a relevant main function to complete the program.

#include <iostream>
using namespace std;


class SELECT {
    private:
        short int list[30]; // Array to store the numbers
        short unsigned int N; // Total number of elements in the array

        void sort() {
            for (short unsigned int i=0; i<N-1; i++) { // Iterate through the array
                short unsigned int minIndex = i; // Assume the current element is the minimum
                for (short unsigned int j=i+1; j<N; j++) { // Find the minimum element in the remaining unsorted part of the array
                    if (list[j] < list[minIndex]) { // If a smaller element is found
                        minIndex = j; // Update the index of the minimum element
                    }
                }
                swap(list[i], list[minIndex]); // Swap the current element with the minimum element
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
        SELECT() {
            cout << "Enter total number of elements (N): ";
            cin >> N;

            cout << "Enter " << N << " numbers for the list: " << endl;
            for (short unsigned int i=0; i<N; i++) { // Iterate through the array
                cout << "Element " << i+1 << ": ";
                cin >> list[i]; // Read each element from the user
            }
            sort(); // Sort the array
            show(); // Display the sorted array
        }
};

int main(void) {
    SELECT selectObj;
}
