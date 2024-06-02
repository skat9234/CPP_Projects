#include <iostream>
using namespace std;



// int main(void) {
//     // *
//     // * *
//     // * * *
//     // * * * *
//     // * * * * *
//     int n;
//     cout << "Enter Number of Rows: ";
//     cin >> n;

//     for (int i=0; i<n; i++) {
//         for (int j=0; j<i; j++) {
//             cout << "* ";
//         }
//         cout << endl;
//     } 
// }

// int main(void) {
//     // * * * * *
//     // * * * *
//     // * * *
//     // * * 
//     // * 
//     int n;
//     cout << "Enter Number of Rows: ";
//     cin >> n;

//     for (int i=0; i<n; i++) {
//         for (int j=n; j>i; j--) {
//             cout << "* ";
//         }
//         cout << endl;
//     } 
// }

int main(void) {
    //         *
    //       * * *
    //     * * * * *
    //   * * * * * * *
    // * * * * * * * * *
    int n, spaces;
    cout << "Enter Number of Rows: ";
    cin >> n;

    for (int i=0, k=0; i<n; ++i, k=0) {
        for ( spaces=0; spaces<n-i; ++spaces) {
            cout << " "; // Print spaces to create the pyramid shape
            while (k != 2*i-1) {
                cout << "* "; // Print asterisks to form the pyramid
                k++;
            }
            cout << endl; // Move to the next line after printing each row
        }
    }
}