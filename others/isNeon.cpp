#include <iostream>

using namespace std;

// Function to check if a number is a neon number
bool isNeon(int number) {
    // Calculate the square of the number
    int square = number * number;
    
    // Initialize sum of digits
    int sumOfDigits = 0;
    
    // Calculate the sum of the digits of the square
    while (square > 0) {
        sumOfDigits += square % 10;
        square /= 10;
    }
    
    // Check if the sum of the digits equals the original number
    return sumOfDigits == number;
}

int main() {
    int number;
    
    // Input number from user
    cout << "Enter a number: ";
    cin >> number;
    
    // Check if the number is a neon number
    if (isNeon(number)) {
        cout << number << " is a neon number." << endl;
    } else {
        cout << number << " is not a neon number." << endl;
    }
    
    return 0;
}
