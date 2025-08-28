// Write a program to delete all the vowels from the string

#include<bits/stdc++.h>
using namespace std;

void deleteVowels(char str[], int &n){
    int i = 0;
    for(int j=0;j<n;j++){
        if (!(str[j]=='A'||str[j]=='E'||str[j]=='I'||str[j]=='O'||str[j]=='U'||
            str[j]=='a'||str[j]=='e'||str[j]=='i'||str[j]=='o'||str[j]=='u')) {
            str[i++] = str[j];
        }
    }
    n = i;
    str[i] = '\0';
}

int main(){
    cout << "Enter a string : ";
    char str[100];
    cin >> str;
    int n = strlen(str);
    deleteVowels(str, n);
    cout << "Updated string after deleting vowels : ";
    for(int i=0; i<n; i++){
        cout << str[i];
    }
    return 0;
}