// Write a program to convert a character from uppercase to lowercase

#include<bits/stdc++.h>
using namespace std;

void upperToLower(char str[], int n){
    for(int i=0; i<n; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

int main(){
    cout << "Enter a string : ";
    char str[100];
    cin >> str;
    int n = strlen(str);
    upperToLower(str, n);
    cout << "Sorted string : ";
    for(int i=0; i<n; i++){
        cout << str[i];
    }
    return 0;
}