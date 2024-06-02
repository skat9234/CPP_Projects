#include <iostream>
using namespace std;

class PRIME
{
private:
    unsigned short int num;
    // Private member function to accept a positive number from the user
    void get_no()
    {
        do
        {
            cout << "Enter a positive number: ";
            cin >> num;
            if (num <= 0)
            {
                cout << "Please enter a positive number." << endl;
            }
        } while (num <= 0);
    }

public:
    // Public member function to check and display whether the num is prime or composite
    void process()
    {
        // Call the private member function 'get_no' to accept a positive number
        get_no();
        bool isPrime = true; // Variable to store whether the number is prime or not, initialized as true
        if (num <= 1) // If the number is less than or equal to 1
        {
            isPrime = false; // Set isPrime as false, as numbers less than or equal to 1 are not prime
        }
        else // If the number is greater than 1
        {
            for (unsigned short int i = 2; i <= num / 2; ++i) // Iterate from 2 to half of the number
            {
                if (num % i == 0) // If the number is divisible by i
                {
                    isPrime = false; // Set isPrime as false, as the number is divisible by i and hence not prime
                    break; // Exit the loop, as we have found a divisor
                }
            }
        }
        if (isPrime)
        {
            cout << num << " is a prime number." << endl;
        }
        else
        {
            cout << num << " is a composite number." << endl;
        }
    }
};
int main(void)
{
    // Create an object of the PRIME class
    PRIME primeObj;
    // Call the public member function 'process' to check if the number is prime or composite
    primeObj.process();
}