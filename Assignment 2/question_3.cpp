// Design the Logic to Find a Missing Number in a Sorted Array

#include<bits/stdc++.h>
using namespace std;

int missingNumber(int arr[], int n){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] > mid+1){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low+1;
}

int main(){
    cout << "Enter number of elements in array : ";
    int n;
    cin >> n;
    cout << "Enter array elements in sorted order : " << endl;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int missing = missingNumber(arr, n);
    cout << "Missing number : " << missing << endl;
    return 0;
}