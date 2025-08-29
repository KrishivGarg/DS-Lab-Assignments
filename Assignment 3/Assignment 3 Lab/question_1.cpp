#include<bits/stdc++.h>
using namespace std;

const int MAXLEN = 10;

typedef struct{
    int top;
    int element[MAXLEN];
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

Stack push(Stack s, int x){
    if(isFull(s)){
        cout << "Overflow" << endl;
    }
    else{
        s.element[++s.top] = x;
    }
    return s;
}

int pop(Stack &s){
    if(isEmpty(s)){
        cout << "Underflow" << endl;
    }
    else{
        return s.element[s.top--];
    }
    return -1;
}

int peek(Stack s){
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
    int choice;
    do{
        cout<<"Enter choice :"<<endl<<"1. for push()"<<endl<<"2. for pop()"<<endl<<"3. for isEmpty()"<<endl<<"4. for isFull()"<<endl<<"5. for display()"<<endl<<"6. for peek()"<<endl<<"7. to exit"<<endl;
        cin >> choice;
        switch(choice){
            case 1: {
                cout << "Enter value to push : ";
                int val;
                cin >> val;
                s = push(s, val);
                break;
            }
            case 2: {
                cout << "Popped : " << pop(s) << endl;
                break;
            }
            case 3: {
                cout << (isEmpty(s) ? "Empty" : "Not empty") << endl; 
                break;
            }
            case 4: {
                cout << (isFull(s) ? "Full" : "Not full") << endl; 
                break;
            }
            case 5: {
                display(s);
                break;
            }
            case 6: {
                cout << "Top most element : " << peek(s) << endl;
                break;
            }
        }
    }
    while(choice != 7);
    return 0;
}
