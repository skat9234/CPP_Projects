#include <iostream>
using namespace std;
class BASE
{
private:
    float num1;

public:
    float num2;
    // Member function to read data value num1
    void input_data()
    {
        cout << "Enter the value for num1: ";
        cin >> num1;
    }
    // Member function to return the value of num1
    float get_num1()
    {
        return num1;
    }
};
class DERIVED : public BASE
{
private:
    float sum;

public:
    // Member function to read num2 and compute sum
    void get_data()
    {
        cout << "Enter the value for num2: ";
        cin >> num2;
        // Call input_data() from the BASE class to read num1
        input_data();
        // Calculate sum by adding num1 and num2
        sum = get_num1() + num2;
    }
    // Member function to output num1, num2, and sum
    void show_data()
    {
        cout << "num1: " << get_num1() << endl;
        cout << "num2: " << num2 << endl;
        cout << "sum: " << sum << endl;
    }
};
int main(void)
{
    // Create an object of the DERIVED class
    DERIVED derivedObj;
    // Call the get_data() function to input num2 and compute sum
    derivedObj.get_data();
    // Call the show_data() function to output num1, num2, and sum
    derivedObj.show_data();
}