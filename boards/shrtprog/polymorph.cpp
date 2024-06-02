#include <iostream>
using namespace std;
// Abstract class BASE1
class BASE1
{
private:
    int A;

public:
    // Inline parameterized constructor to initialize data member "A"
    inline BASE1(int a) : A(a) {}
    // Inline protected member function that returns the value of "A"
    inline int Get_A()
    {
        return A;
    }
    // Pure virtual function (making it an abstract class)
    virtual void display() = 0;
};
// Abstract class BASE2
class BASE2
{
private:
    int B;

public:
    // Inline parameterized constructor to initialize data member "B"
    inline BASE2(int b) : B(b) {}
    // Inline public member function that returns the value of "B"
    inline int Get_B()
    {
        return B;
    }
    // Pure virtual function (making it an abstract class)
    virtual void display() = 0;
};
// Derived class DERIVED
class DERIVED : public BASE1, protected BASE2
{
private:
    int Z;

public:
    // Inline parameterized constructor to initialize data member "Z"
    inline DERIVED(int a, int b) : BASE1(a), BASE2(b)
    {
        Z = Get_A() * Get_B();
        show();
    }

private:
    // Inline private member function that displays the value of Z
    inline void show()
    {
        cout << "Z: " << Z << endl;
    }

public:
    // Public member function to fulfill the pure virtual function in BASE1
    void display() override
    {
        // Implementation is not needed for this example
    }
};
int main(void)
{
    // Create an object of the DERIVED class
    DERIVED derivedObj(3, 5);
}