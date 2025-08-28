// Implement the Binary search algorithm regarded as a fast search algorithm with run-time
// complexity of Ο(log n) in comparison to the Linear Search. 

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int target){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
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
    cout << "Enter element to search : ";
    int element;
    cin >> element;
    int index = binarySearch(arr, n, element);
    if(index == -1){
        cout << "Element not found" << endl;
    }
    else{
        cout << "Element found at index : " << index << endl;
    }
    return 0;
}