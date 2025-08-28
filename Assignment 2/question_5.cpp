#include <bits/stdc++.h>
using namespace std;

// (a) Diagonal Matrix
void diagonalMatrix(int n) {
    int A[n];  
    cout << "\nDiagonal Matrix: Enter " << n << " diagonal elements:\n";
    for (int i=0; i<n; i++) cin >> A[i];

    cout << "Matrix:\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==j) cout << A[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

// (b) Tri-diagonal Matrix
void triDiagonalMatrix(int n) {
    int size = 3*n - 2;
    int A[size];
    cout << "\nTri-Diagonal Matrix: Enter " << size << " elements (lower, main, upper diagonals):\n";
    for (int i=0; i<size; i++) cin >> A[i];

    cout << "Matrix:\n";
    int k=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==j) cout << A[n-1 + i] << " ";           
            else if (i-j==1) cout << A[i-1] << " ";      
            else if (j-i==1) cout << A[2*n -1 + i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

// (c) Lower Triangular Matrix
void lowerTriangularMatrix(int n) {
    int size = n*(n+1)/2;
    int A[size];
    cout << "\nLower Triangular Matrix: Enter " << size << " elements:\n";
    for (int i=0; i<size; i++) cin >> A[i];

    cout << "Matrix:\n";
    int k=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i >= j) cout << A[k++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

// (d) Upper Triangular Matrix
void upperTriangularMatrix(int n) {
    int size = n*(n+1)/2;
    int A[size];
    cout << "\nUpper Triangular Matrix: Enter " << size << " elements:\n";
    for (int i=0; i<size; i++) cin >> A[i];

    cout << "Matrix:\n";
    int k=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i <= j) cout << A[k++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

// (e) Symmetric Matrix
void symmetricMatrix(int n) {
    int size = n*(n+1)/2;
    int A[size];
    cout << "\nSymmetric Matrix: Enter " << size << " elements of LOWER triangle:\n";
    for (int i=0; i<size; i++) cin >> A[i];

    cout << "Matrix:\n";
    int k=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i >= j) cout << A[k++] << " ";           
            else cout << A[j*(j+1)/2 + i] << " ";     
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of square matrix (n): ";
    cin >> n;

    diagonalMatrix(n);
    triDiagonalMatrix(n);
    lowerTriangularMatrix(n);
    upperTriangularMatrix(n);
    symmetricMatrix(n);

    return 0;
}
