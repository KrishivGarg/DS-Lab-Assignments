// Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion
// if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the number
// of inversions in an array

#include<bits/stdc++.h>
using namespace std;

int findInversions(int arr[], int n){
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                count++;
            }
        }
    }
    return count;
}

int main(){
    cout << "Enter number of elements in array : ";
    int n;
    cin >> n;
    cout << "Enter array elements : " << endl;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Total Inversions : " << findInversions(arr, n);
    return 0;
}