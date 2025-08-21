// Developa Menudrivenprogramtodemonstrate the followingoperations of Arrays
// ——MENU——-
// 1.CREATE
// 2.DISPLAY
// 3.INSERT
// 4.DELETE
// 5.LINEAR SEARCH
// 6.EXIT


#include<bits/stdc++.h>
using namespace std;

void create(){
    int n;
    cout << "Enter number of elements in array : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << endl;
}

void display(int arr[], int n){
    cout << "Array : " << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert(int arr[], int &n, int position, int element){
    n++;
    arr[n];
    for(int i=n-1; i>position; i--){
        arr[i] = arr[i-1];
    }
    arr[position] = element;
}

void del(int arr[], int &n, int position){
    for(int i=position; i<n-1; i++){
        arr[i] = arr[i+1];
    }
    n--;
    arr[n];
}

int linearSearch(int arr[], int n, int element){
    int index = -1;
    for(int i=0; i<n; i++){
        if(arr[i] == element){
            index = i;
            break;
        }
    }
    return index;
}

int main(){
    cout <<"---MENU---"<< endl <<"1.CREATE"<< endl <<"2.DISPLAY"<< endl <<"3.INSERT" << endl <<"4.DELETE"<< endl <<"5.LINEAR SEARCH"<< endl <<"6.EXIT"<< endl; 
    int choice;
    cout << "Enter your choice as per the menu  : ";
    cin >> choice;
    int n;
    int arr[n];
    if(choice >= 2 && choice <=5){
        cout << "Enter number of elements in array : ";
        cin >> n;
        cout << "Enter elements : " << endl;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        cout << endl;
    }
    switch(choice){
        case 1:{
            create();
            break;
        }
        case 2:{
            display(arr, n);
            break;
        }
        case 3:{
            int position;
            cout << "Enter position to insert : ";
            cin >> position;
            int element;
            cout << "Enter element to insert : ";
            cin >> element;
            insert(arr, n, position, element);
            for(int i=0; i<n; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }
        case 4:{
            int position;
            cout << "Enter position to delete : ";
            cin >> position;
            del(arr, n, position);
            for(int i=0; i<n; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }
        case 5:{
            int element;
            cout << "Enter element to search : ";
            cin >> element;
            int index = linearSearch(arr, n, element);
            if(index != -1){
                cout << "Element " << element << " found at index : " << index;
            }
            else{
                cout << "Element " << element << " not found";
            }
            cout << endl;
            break;
        }
        case 6:{
            cout << "Program exited successfully" << endl;
            break;
        }
        default:{
            cout << "Invalid input choice" << endl;
        }
    }
    return 0;
}