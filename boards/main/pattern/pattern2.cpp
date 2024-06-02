#include <iostream>
using namespace std;


int main(void) {

// A
// BB
// CCC
// DDDD
// EEEE

    int n;
    char a = 'A';
    cout << "Enter Number of Rows: ";
    cin >> n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<i+1; j++) {
            cout << a << " ";
        }
        a++;
        cout << endl;
    }
}



// }

// int main() {
//     int rows = 5;
//     int num = 1;

    
//     for (int i = rows - 1; i >= 1; --i) {
//         // Print spaces before asterisks
//         for (int space = 1; space <= rows - i; ++space) {
//             cout << " ";
//         }

//         // Print asterisks
//         for (int asterisk = 1; asterisk <= 2 * i - 1; ++asterisk) {
//             cout << num << " ";
//         }
//         num++;
//         cout << endl;
//     }
// }
    
// int main() {
//     int n;

//     cout << "Enter the number of rows for the triangle: ";
//     cin >> n;

//     // Printing the upside-down hollow equilateral triangle
//     for (int i = n; i >= 1; i--) {
//         // Print spaces before the numbers
//         for (int j = 1; j <= n - i; j++) {
//             cout << " ";
//         }

//         // Print numbers and spaces
//         for (int k = 1; k <= 2 * i - 1; k++) {
//             if (i == n || k == 1 || k == 2 * i - 1) {
//                 cout << i;
//             } else {
//                 cout << " ";
//             }
//         }

//         cout << endl;
//     }

//     return 0;
// }


#include <iostream>
using namespace std;

int main() {
    int rows;

    cout << "Enter the number of rows: ";
    cin >> rows;

    const int columns = 5; // Fixing the number of columns to 5

    // Printing the hollow rectangle pattern
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            if (i == 1 || i == rows || j == 1 || j == columns) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}