// Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent
// elements if they are in wrong order. Code the Bubble sort with the following elements:
// 64 34 25 12 22 11 90

#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n){
    for(int i=n-1; i>=1; i--){
        int didSwap = 0;
        for(int j=0; j<=i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                didSwap ++;
            }
        }
        if(didSwap == 0) break;
    }
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    cout << "Array : " << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    bubble_sort(arr, n);
    cout << endl << "Sorted array : " << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}