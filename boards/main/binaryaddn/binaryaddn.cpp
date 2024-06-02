#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    long bn1, bn2;
    int i=0, r=0, sum[20];
    cout << "Input the First Binary Number: ";
    cin >> bn1;
    cout << "Enter the Second Binary Number: ";
    cin >> bn2;

    while (bn1 != 0 || bn2 != 0) {
        sum[i++] = (int) ((bn1 % 10 + bn2 % 10 + r) % 2);
        r = (int) ((bn1 % 10 + bn2 % 10 + r) / 2);
        bn1 /= 10;
        bn2 /= 10;
    }
    if (r != 0) {
        sum[i++] = r;
        i--;
        cout << "The Sum of Two Binary Number is: ";
        while(i>=0) {
            cout << (sum[i--]);
        }
        cout << endl;
    }
}