#include <iostream>
#include <cmath>
using namespace std;

class SERIES
{
private:
    unsigned short int N;
    float D;
    // Private member function to compute factorial of a number
    unsigned long long int factorial(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        else
        {
            return n * factorial(n - 1);
        }
    }
    // Private member function to compute sin(x) using the given series
    void process()
    {
        // Convert angle from degrees to radians
        float x = D * (3.14159265359 / 180.0);
        float result = 0.0;
        int sign = 1;
        for (unsigned short int i = 1, j = 1; i <= N; ++i, j += 2)
        {
            result += sign * (pow(x, j) / factorial(j));
            sign *= -1;
        }
        cout << "sin(" << D << " degrees) = " << result << endl;
    }

public:
    // Public member function to read values for the data members D and N and call the process function
    void get_data()
    {
        cout << "Enter the angle in degrees (D): ";
        cin >> D;
        cout << "Enter the number of terms (N): ";
        cin >> N;
        // Call the private member function 'process' to compute sin(x) using the given series
        process();
    }
};
int main(void)
{
    // Create an object of the SERIES class
    SERIES seriesObj;
    // Call the public member function 'get_data' to read values and compute sin(x)
    seriesObj.get_data();
}