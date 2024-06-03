#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    int temp = number;
    int digits[10]; // Assuming the number won't have more than 10 digits
    int count = 0;

    // Extract digits and store them in reverse order
    while (temp > 0) { // Loop until temp becomes 0
        digits[count++] = temp % 10; // Extract the last digit of temp and store it in the digits array
        temp /= 10; // Remove the last digit from temp
    }
    // Print digits in correct order
    cout << "Digits: ";
    for (int i = count - 1; i >= 0; --i) {
        cout << digits[i] << " ";
    }
    cout << endl;

    return 0;
}
