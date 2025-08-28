// Write a program to reverse a string

#include<bits/stdc++.h>
using namespace std;

void reverseString(char str[], int n){
    for(int i=0;i<n/2;i++){
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
}

int main(){
    cout << "Enter a string : ";
    char str[100];
    cin >> str;
    int n = strlen(str);
    reverseString(str, n);
    cout << "Reversed string : ";
    for(int i=0; i<n; i++){
        cout << str[i];
    }
    return 0;
}