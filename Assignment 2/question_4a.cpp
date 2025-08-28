// Write a program to concatenate one string to another string

#include<bits/stdc++.h>
using namespace std;

void concatenateString(char str1[], int &n, char str2[], int m){
    for(int i=n;i<n+m;i++){
        str1[i] = str2[i-n];
    }
    n = n+m;
    str1[n] = '\0';
}

int main(){
    cout << "Enter first string : ";
    char str1[100];
    cin >> str1;
    int n = strlen(str1);
    cout << "Enter second string : ";
    char str2[100];
    cin >> str2;
    int m = strlen(str2);
    concatenateString(str1, n, str2, m);
    cout << "Concatenated string : ";
    for(int i=0; i<n; i++){
        cout << str1[i];
    }
    return 0;
}