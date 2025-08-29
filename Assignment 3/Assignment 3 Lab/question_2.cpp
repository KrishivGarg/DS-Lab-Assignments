#include<bits/stdc++.h>
using namespace std;

const int MAXLEN = 100;

typedef struct{
    int top;
    char element[MAXLEN];
} Stack;

Stack init(Stack s){
    s.top = -1;
    return s;
}

int isEmpty(Stack s){
    return (s.top == -1);
}

int isFull(Stack s){
    return (s.top == MAXLEN-1);
}

void push(Stack &s, char x){
    if(isFull(s)){
        cout << "Overflow" << endl;
    }
    else{
        s.element[++s.top] = x;
    }
}

char pop(Stack &s){
    if(isEmpty(s)){
        cout << "Underflow" << endl;
    }
    else{
        return s.element[s.top--];
    }
    return -1;
}

char peek(Stack s){
    if(isEmpty(s)){
        cout << "Underflow" << endl;
    }
    else{
        return s.element[s.top];
    }
    return -1;
}

void display(Stack s){
    if(isEmpty(s)){
        cout << "Underflow" << endl;
    }
    else{
        for(int i=s.top; i>=0; i--){
            cout << s.element[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    Stack s;
    s = init(s);
    char str[100];
    cout << "Enter a string : ";
    cin >> str;
    int i = 0;
    while(str[i] != '\0'){
        push(s, str[i++]);
    }
    char rev[100]; 
    int j = 0;
    while(!isEmpty(s)){
        rev[j++] = pop(s);
    }
    rev[j] = '\0';
    int k = 0;
    while(rev[k] != '\0'){
        cout << rev[k++];
    }
    return 0;

}
