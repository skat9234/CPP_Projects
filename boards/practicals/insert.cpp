// Define a class named INSERT consisting of the following members:
//  i) list: an array of type short integer of size 30 under private visibility
//      label.
//  ii) N : of type short unsigned integer(indicates total number of elements to
//      be accepted in array “list” ) under private visibility label.
//  iii) Define a default constructor to accept data member “N” and to accept the
//      numbers in the array “list”. It further calls member function “sort” followed by
//      member function “show”.
//  iv) Define a private member function named “sort” which performs sorting of
//      numbers in the array “list” using insertion sort technique (sort in ASCENDING
//      order).
//  v) Define a private member function named “show” which displays the content of
//      array.
// Write a relevant main function to complete the program.


#include <iostream>  // Include the input/output stream library

using namespace std;  // Use the standard namespace

class INSERT {  // Define a class named INSERT
    private:  // Private section of the class
        short int list[30];  // Declare an array of type short integer with size 30
        short unsigned int N;  // Declare a variable of type short unsigned integer

        void sort() {  // Define a private member function named "sort"
            for (short unsigned int i=1; i<N; i++) {  // Iterate through the array
                short int key = list[i];  // Store the current element in a variable
                short int j = i-1;  // Initialize a variable to the previous index

                while (j>=0 && list[j] > key) {  // Perform insertion sort
                    list[j+1] = list[j];  // Shift elements to the right
                    j--;  // Move to the previous index
                }

                list[j+1] = key;  // Insert the current element at the correct position
            }
        }

        void show() {  // Define a private member function named "show"
            cout << "Sorted Array: ";  // Print a message
            for (short unsigned int i=0; i<N; i++) {  // Iterate through the array
                cout << list[i] << " ";  // Print each element
            } 
            cout << endl;  // Print a new line
        }

    public:  // Public section of the class
        INSERT() {  // Define a default constructor
            cout << "Enter the total number of elements (N): ";  // Prompt the user for input
            cin >> N;  // Read the value of N from the user

            cout << "Enter " << N << " elements: " << endl;  // Prompt the user for input
            for (short unsigned int i=0; i<N; i++) {  // Iterate through the array
                cout << "Element " << i+1 << ": " ;  // Prompt the user for input
                cin >> list[i];  // Read the elements from the user
            }
            sort();  // Call the private member function "sort" to sort the array
            show();  // Call the private member function "show" to display the sorted array
        }
};

int main(void) {  // The entry point of the program
    INSERT insertObj;  // Create an object of the INSERT class
}

