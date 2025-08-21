// Reverse the elements of an array

#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int n){
    for(int i=0; i<n/2; i++){
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

int main(){
    int n;
    cout << "Enter number of elements in array : ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements : ";
    for(int i=0; i<n; i++) cin >> arr[i];
    reverseArray(arr, n);
    cout << "Reversed array : ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}