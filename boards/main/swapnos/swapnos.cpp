#include <iostream>
using namespace std;

// Using third variable
// int main(void) {
//     int a, b, t;
//     cout << "Enter Value of N-1: ";
//     cin >> a;
//     cout << "Enter Value of N-2: ";
//     cin >> b;

//     cout << "Before Swap: a=" << a << " & b=" << b << endl;

//     t = a;
//     a = b;
//     b = t;

//     cout << "After Swap: a=" << a << " & b=" << b << endl;
// }

// Without Using Third Variable
int main(void) {
    int a,b;
    cout << "Enter Value of N-1: ";
    cin >> a;
    cout << "Enter Value of N-2: ";
    cin >> b;

    cout << "Before Swap: a=" << a << " & b=" << b << endl;

    a = a+b;
    b = a-b;
    a = a-b;
    
    cout << "After Swap: a=" << a << " & b=" << b << endl;


}