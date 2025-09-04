// Write a program for the evaluation of a Postfix expression

#include <bits/stdc++.h>
using namespace std;

const int MAXLEN = 100;

typedef struct {
    int top;
    int element[MAXLEN];  
} Stack;

Stack init(Stack s) {
    s.top = -1;
    return s;
}

int isEmpty(Stack s) {
    return (s.top == -1);
}

int isFull(Stack s) {
    return (s.top == MAXLEN - 1);
}

void push(Stack &s, int x) {
    if (isFull(s)) {
        cout << "Overflow" << endl;
    } else {
        s.element[++s.top] = x;
    }
}

int pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Underflow" << endl;
        return -1;
    } else {
        return s.element[s.top--];
    }
}

int peek(Stack s) {
    if (isEmpty(s)) {
        return -1;
    } else {
        return s.element[s.top];
    }
}

int evaluatePostfix(const char* postfix) {
    Stack s;
    s = init(s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            push(s, c - '0');
        }
        else {
            int val2 = pop(s);
            int val1 = pop(s);
            switch (c) {
                case '+': push(s, val1 + val2); break;
                case '-': push(s, val1 - val2); break;
                case '*': push(s, val1 * val2); break;
                case '/': push(s, val1 / val2); break;
                case '^': push(s, pow(val1, val2)); break;
            }
        }
    }
    return pop(s);  
}

int main() {
    char postfix[MAXLEN];
    cout << "Enter Postfix expression: ";
    cin.getline(postfix, MAXLEN);
    int result = evaluatePostfix(postfix);
    cout << "Evaluation : " << result << endl;
    return 0;
}
