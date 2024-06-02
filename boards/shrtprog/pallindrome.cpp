#include <iostream>
using namespace std;
class NUMBER
{
private:
    short unsigned int num;
    // Private member function to check if the number is palindrome
    int isPalindrome()
    {
        short unsigned int originalNum = num;
        short unsigned int reversedNum = 0;
        // Reverse the number
        while (originalNum != 0)
        {
            reversedNum = reversedNum * 10 + originalNum % 10;
            originalNum /= 10;
        }
        // Check if the reversed number is equal to the original number
        return (num == reversedNum) ? 1 : 0;
    }

public:
    // Public member function to display whether the number is palindrome or not
    void display()
    {
        // Call the private member function 'input' to accept the number
        cout << "Enter a number: ";
        cin >> num;
        // Check if the number is palindrome and display the result
        if (isPalindrome())
        {
            cout << num << " is a palindrome." << endl;
        }
        else
        {
            cout << num << " is not a palindrome." << endl;
        }
    }
};
int main(void)
{
    // Create an object of the NUMBER class
    NUMBER numObj;
    // Call the public member function 'display' to check if the number is palindrome
    numObj.display();
}