#include <iostream>
#include <cmath>

using namespace std;

// Function to convert binary to decimal
int binaryToDecimal(int N) {
    int decimalNumber = 0;
    int base = 1; // 2^0

    while (N > 0) {
        int lastDigit = N % 10;
        decimalNumber += lastDigit * base;
        base *= 2;
        N /= 10;
    }

    return decimalNumber;
}

int main() {
    int N;
    
    // Input binary number from user
    cout << "Enter a binary number: ";
    cin >> N;
    
    // Convert binary to decimal
    int decimalNumber = binaryToDecimal(N);
    
    // Output the result
    cout << "The decimal equivalent of binary " << N << " is " << decimalNumber << "." << endl;
    
    return 0;
}