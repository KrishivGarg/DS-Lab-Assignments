// Write a program to convert an Infix expression into a Postfix expression

#include <bits/stdc++.h>
using namespace std;

const int MAXLEN = 100;

typedef struct {
    int top;
    char element[MAXLEN];
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

void push(Stack &s, char x) {
    if (isFull(s)) {
        cout << "Overflow" << endl;
    } else {
        s.element[++s.top] = x;
    }
}

char pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Underflow" << endl;
        return '\0';
    } else {
        return s.element[s.top--];
    }
}

char peek(Stack s) {
    if (isEmpty(s)) {
        return '\0';
    } else {
        return s.element[s.top];
    }
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(const char *infix, char *postfix) {
    Stack s;
    s = init(s);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) { 
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(s, c);
        }
        else if (c == ')') {
            while (!isEmpty(s) && peek(s) != '(') {
                postfix[j++] = pop(s);
            }
            if (!isEmpty(s)) pop(s); 
        }
        else { 
            while (!isEmpty(s) && precedence(peek(s)) >= precedence(c)) {
                if (c == '^' && peek(s) == '^') break; 
                postfix[j++] = pop(s);
            }
            push(s, c);
        }
    }

    while (!isEmpty(s)) {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAXLEN], postfix[MAXLEN];
    cout << "Enter Infix expression: ";
    cin.getline(infix, MAXLEN);

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
