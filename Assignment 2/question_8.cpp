// Write a program to count the total number of distinct elements in an array of length n

#include<bits/stdc++.h>
using namespace std;

int distinctElements(int arr[], int n){
    sort(arr, arr+n);
    int count = 0;
    for(int i=1; i<n; i++){
        if(arr[i-1] != arr[i]){
            count++;
        }
    }
    return count+1;
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
    cout << "Total distinct elements : " << distinctElements(arr, n);
    return 0;
}