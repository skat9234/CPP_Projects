// Define a class named MERGE consisting of the following members:
//  i) A,B,C: 1-D arrays of type short integer of size 50 each under private
// visibility label.
//  ii) M,N : of type short unsigned integer (indicates total number of elements in
//      A and B respectively ) under private visibility label.
//  iii) Define a default constructor to accept data members “M” and “N” and to
//      accept the numbers in the arrays A and B (both in ascending order). It
//      further calls member function “process”.
//  iv) Define a private member function named “process” which performs
//      merging of all elements in A and B to obtain array C in ASCENDING
//      order for display.
//      Write a relevant main function to complete the program.

#include <iostream>
using namespace std;

class MERGE {
    private:
        short int A[50], B[50], C[50];
        short unsigned int M, N;

        void process() {
            short unsigned int i=0, j=0, k=0;
            while (i<M && j<N) {
                if(A[i] < B[j]) {
                    C[k++] = A[i++];
                } else {
                    C[k++] = B[j++];
                }
            }
            while(i < M) {
                C[k++] = A[i++];
            }
            while(j < N) {
                C[k++] = B[j++];
            }
        }
    
    public:
        MERGE() {
            cout << "Enter total number of elements in array A (M): ";
            cin >> M;
            
            cout << "Enter " << M << " Number for array A (ascending order): " << endl;
            for (short unsigned int i = 0; i < M; i++) {
                cout << "Element " << i+1 << ": ";
                cin >> A[i];
            }

            cout << "Enter total number of elements in array B (N): ";
            cin >> N;
            
            cout << "Enter " << N << " Number for array B (ascending order): " << endl;
            for (short unsigned int i = 0; i < N; i++) {
                cout << "Element " << i+1 << ": ";
                cin >> B[i];
            }

            process();

            cout << "Merged Array (C): ";
            for (short unsigned int i=0; i < M+N; i++) {
                cout << C[i] << " ";
            }
            cout << endl;
        }
};

int main(void) {
    MERGE mergeObj;
}