#include <iostream>
using namespace std;

int main(void) {
    int n, t1=0, t2=1, nextTerm=0;
    cout << "Enter the Number of Terms: ";
    cin >> n;
    cout << "Fibonacci Series: " << endl;
    for (int i=1; i<=n; i++) {
        if (i==1) {
            cout << t1 << ", ";
            continue;
        }
        if (i==2) {
            cout << t2 << ", ";
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        cout << nextTerm << ", ";
    }
}