// Define a class named BINARY consisting of the following members:
//  i) list: an array of type short integer of size 30 under private visibility label.
//  ii) N : of type short unsigned integer (indicates total number of elements to be
//      accepted in array “list” ) under private visibility label.
//  iii) Define a default constructor to accept data member “N” and to accept
//      the numbers in the array “list”. It further calls member function “search”.
//  iv) Define a private member function named “search” which accepts the
//      number to be searched from the user and determines whether it is present
//      in the “list” using binary search technique.
// Write a relevant main function to complete the program.

#include <iostream>
using namespace std;

class BINARY {
    private:
        short int list[30];
        short unsigned int N;

        void search(short int num) {
            int low = 0, high = N-1;
            bool found = false;

            while (low <= high) {
                int mid = low + (high-low)/2;
                if (list[mid] == num) {
                    cout << "Number " << num << " Found at Index: " << mid << endl;
                    found = true;
                    break; 
                }
                else if (list[mid] < num) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            if (!found) {
                cout << "Number " << num << " Not found in the list." << endl;
            }
        }
    
    public:
        BINARY() {
            cout << "Enter the total number of elements(N): ";
            cin >> N;

            cout << "Enter " << N << " Numbers for the list (ascending order): " << endl;
            for (short unsigned int i = 0; i<N; i++) {
                cout << "Element " << i+1 << ": ";
                cin >> list[i];
            }

            int numToSearch;
            cout << "Enter Number to be searched: ";
            cin >> numToSearch;
            search(numToSearch);
        }
};

int main(void) {
    BINARY binaryObj;
}
