// Find the matrix multiplication

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Matrix 1 :" << endl;
    int n1, m1;
    cout << "Enter number of rows and columns : ";
    cin >> n1 >> m1;
    int matrix1[n1][m1];
    cout << "Enter elements : " << endl;
    for(int i=0; i<n1; i++){
        for(int j=0; j<m1; j++){
            cin >> matrix1[i][j];
        }
    }

    cout << "Matrix 2 :" << endl;
    int n2, m2;
    cout << "Enter number of rows and columns : ";
    cin >> n2 >> m2;
    int matrix2[n2][m2];
    cout << "Enter elements : " << endl;
    for(int i=0; i<n2; i++){
        for(int j=0; j<m2; j++){
            cin >> matrix2[i][j];
        }
    }

    if(m1 != n2){
        cout << "Matrix multiplication not possible";
        return 0;
    }
    int matrix[n1][m2] = {0};

    for (int i = 0; i < n1; i++){
        for (int j = 0; j < m2; j++){
            for (int k = 0; k < m1; k++){
                    matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    cout << "Matrix Multiplication : " << endl;
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < m2; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}