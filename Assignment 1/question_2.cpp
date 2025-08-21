// Design the logic to remove the duplicate elements from an Array and after the
// deletion the array should containtheunique elements.

#include<bits/stdc++.h>
using namespace std;

void removeDuplicates(int arr[], int &n){
    sort(arr, arr+n);
    int i = 0;
    for(int j=1; j<n; j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    n = i+1;
}

int main(){
    int n;
    cout << "Enter number of elements in array : ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements : ";
    for(int i=0; i<n; i++) cin >> arr[i];
    removeDuplicates(arr, n);
    cout << "Updated array with unique elements : ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}