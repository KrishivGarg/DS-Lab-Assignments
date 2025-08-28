// Write a program to sort the strings in alphabetical order

#include<bits/stdc++.h>
using namespace std;

void sortAlphabetically(char str[], int n){
    for(int i=n-1; i>=1; i--){
        int didSwap = 0;
        for(int j=0; j<=i-1; j++){
            if(str[j] > str[j+1]){
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
                didSwap++;
            }
        }
        if(didSwap == 0){
            break;
        }
    }
}

int main(){
    cout << "Enter a string : ";
    char str[100];
    cin >> str;
    int n = strlen(str);
    sortAlphabetically(str, n);
    cout << "Sorted string : ";
    for(int i=0; i<n; i++){
        cout << str[i];
    }
    return 0;
}