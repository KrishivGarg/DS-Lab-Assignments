// Write a program to find sum of every row and every column in a two-dimensional array

#include<bits/stdc++.h>
using namespace std;

int main(){
    int rows, cols;
    cout << "Enter number of rows and columns : ";
    cin >> rows >> cols;

    int arr[rows][cols];
    cout << "Enter elements : " << endl;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin >> arr[i][j];
        }
    }
    
    cout << endl;

    for(int i=0; i<rows; i++){
        int row_sum = 0;
        for(int j=0; j<cols; j++){
            row_sum  += arr[i][j];
        }
        cout << "Row " << i+1 << " : sum = " << row_sum << endl;
    }

    cout << endl;
    
    for(int i=0; i<cols; i++){
        int col_sum = 0;
        for(int j=0; j<rows; j++){
            col_sum  += arr[j][i];
        }
        cout << "Column " << i+1 << " : sum = " << col_sum << endl;
    }
    
    return 0;
}