 #include <iostream>
 using namespace std;

 int main() {
 // Declaring 2D array
 int m, n;
 cout << "enter m & n";
cin >> m;
cin >> n;
int arr[m][n];

 // Initialize 2D array using loop
 for (int i = 0; i < m; i++) {
     for (int j = 0; j < n; j++) {
        arr[i][j] = i + j;
    }
 }
 // Printing the element of 2D array
for (int i = 0; i < m; i++) {
     for (int j = 0; j < n; j++) {
        cout << arr[i][j] << " ";
    }

cout << endl;

  }
 
 }


 