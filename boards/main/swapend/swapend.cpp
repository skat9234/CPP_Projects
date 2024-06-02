#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, first, last, sum, digits, nn, a, b;
    cout << "Input any number: ";
    cin >> n;
    digits = (int)log10(n);
    first = n / pow(10, digits);
    last = n % 10;
    a = first * (pow(10, digits));
    b = n % a;
    n = b / 10;
    nn = last * (pow(10, digits)) + (n * 10 + first);
    cout << "The number after swapping the first and last digits are : " << nn << endl;
}