// Define a class named MATRIX consisting of the following members:
//  i) M.N,Q: of type short unsigned integer under private visibility label.
//  ii) A,B,C : 2-D arrays of size 10x10 each under private visibility label.
//  iii) Define a default constructor to accept data members M,N and Q (Where MxN
//      is size of A and NxQ is size of B). It also accepts 2-D array A and B.
//      It further calls member function “product”.
//  iv) Define a private member function named “product” which computes product of
//      two matrix’s A and B and stores in C. It further displays matrix C in tabular
//      form.
// Write a relevant main function to complete the program.

#include <iostream>
using namespace std;

class MATRIX {
    private:
        short unsigned int M,N,Q;
        int A[10][10], B[10][10], C[10][10];

        void product() {
            for (short unsigned int i=0; i<M; i++) {
                for (short unsigned int j=0; j<Q; j++) {
                    C[i][j] = 0;
                    for (short unsigned int k=0; k<N; k++) {
                        C[i][j] += A[i][k] * B[k][j]; 
                    }
                }
            }
        }

    public:
        MATRIX() {
            cout << "Enter number of rows for matrix A (M): ";
            cin >> M;

            cout << "Enter number of columns for matrix A & rows for matrix B (N): ";
            cin >> N;

            cout << "Enter number of columns for matrix B (Q): ";
            cin >> Q;

            cout << "Enter elements for matrix A (" << M << "x" << N << "):" << endl;
            for (short unsigned int i=0; i<M; i++) {
                for (short unsigned int j=0; j<N; j++) {
                    cout << "Element A [" << i+1 << "][" << j+1 << "]: ";
                    cin >> A[i][j];
                }
            }

            cout << "Enter elements for matrix B (" << N << "x" << Q << "):" << endl;
            for (short unsigned int i=0; i<N; i++) {
                for (short unsigned int j=0; j<Q; j++) {
                    cout << "Element B [" << i+1 << "][" << j+1 << "]: ";
                    cin >> B[i][j];
                }
            }
            product();

            cout << "Product Matrix C (" << M << "x" << Q << "):" << endl;
            for (short unsigned int i=0; i<M; i++) {
                for (short unsigned int j=0; j<Q; j++) {
                    cout << C[i][j] << "\t";
                }
                cout << endl;
            }
        }
};

int main(void) {
    MATRIX matrixObj;
}