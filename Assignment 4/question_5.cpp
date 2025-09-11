#include <bits/stdc++.h>
using namespace std;

const int MAXLEN = 100;

typedef struct {
    int element[MAXLEN];
    int front, rear;
} Queue;

Queue init(Queue Q) { Q.front = Q.rear = -1; return Q; }
bool isEmpty(Queue Q) { return (Q.front == -1); }
bool isFull(Queue Q) { return (Q.rear == MAXLEN-1); }

Queue enqueue(Queue Q, int x) {
    if (isFull(Q)) cout << "Overflow\n";
    else {
        if (isEmpty(Q)) Q.front = 0;
        Q.rear++;
        Q.element[Q.rear] = x;
    }
    return Q;
}

Queue dequeue(Queue Q, int &item) {
    if (isEmpty(Q)) cout << "Underflow\n";
    else {
        item = Q.element[Q.front];
        if (Q.front == Q.rear) Q.front = Q.rear = -1;
        else Q.front++;
    }
    return Q;
}

int peek(Queue Q) {
    if (isEmpty(Q)) return -1;
    return Q.element[Q.front];
}

int size(Queue Q) {
    if (isEmpty(Q)) return 0;
    return Q.rear - Q.front + 1;
}

typedef struct {
    Queue q1, q2;
} Stack2Q;

Stack2Q initStack2Q(Stack2Q S) {
    S.q1 = init(S.q1);
    S.q2 = init(S.q2);
    return S;
}

Stack2Q push(Stack2Q S, int x) {
    S.q2 = enqueue(S.q2, x);
    int temp;
    while (!isEmpty(S.q1)) {
        S.q1 = dequeue(S.q1, temp);
        S.q2 = enqueue(S.q2, temp);
    }
    Queue t = S.q1;
    S.q1 = S.q2;
    S.q2 = t;
    return S;
}

Stack2Q pop(Stack2Q S) {
    int temp;
    if (isEmpty(S.q1)) cout << "Stack Underflow\n";
    else {
        S.q1 = dequeue(S.q1, temp);
        cout << "Popped: " << temp << endl;
    }
    return S;
}

int top(Stack2Q S) { return peek(S.q1); }

void display(Stack2Q S) {
    if (isEmpty(S.q1)) cout << "Stack Empty\n";
    else {
        cout << "Stack(top->bottom): ";
        for (int i = S.q1.front; i <= S.q1.rear; i++)
            cout << S.q1.element[i] << " ";
        cout << endl;
    }
}

typedef struct {
    Queue q;
} Stack1Q;

Stack1Q initStack1Q(Stack1Q S) {
    S.q = init(S.q);
    return S;
}

Stack1Q push(Stack1Q S, int x) {
    S.q = enqueue(S.q, x);
    int sz = size(S.q);
    for (int i = 0; i < sz-1; i++) {
        int temp;
        S.q = dequeue(S.q, temp);
        S.q = enqueue(S.q, temp);
    }
    return S;
}

Stack1Q pop(Stack1Q S) {
    int temp;
    if (isEmpty(S.q)) cout << "Stack Underflow\n";
    else {
        S.q = dequeue(S.q, temp);
        cout << "Popped: " << temp << endl;
    }
    return S;
}

int top(Stack1Q S) { return peek(S.q); }

void display(Stack1Q S) {
    if (isEmpty(S.q)) cout << "Stack Empty\n";
    else {
        cout << "Stack(top->bottom): ";
        for (int i = S.q.front; i <= S.q.rear; i++)
            cout << S.q.element[i] << " ";
        cout << endl;
    }
}

int main() {
    int implChoice;
    cout << "Choose Stack Implementation:\n";
    cout << "1. Using Two Queues\n";
    cout << "2. Using One Queue\n";
    cin >> implChoice;

    if (implChoice == 1) {
        Stack2Q S;
        S = initStack2Q(S);
        int choice;
        do {
            cout << "\nStack using Two Queues\n";
            cout << "1.Push\n2.Pop\n3.Top\n4.Display\n5.Exit\n";
            cin >> choice;
            switch(choice) {
                case 1: { int val; cout << "Enter value: "; cin >> val; S = push(S,val); break; }
                case 2: S = pop(S); break;
                case 3: cout << "Top element: " << top(S) << endl; break;
                case 4: display(S); break;
            }
        } while(choice != 5);
    }
    else if (implChoice == 2) {
        Stack1Q S;
        S = initStack1Q(S);
        int choice;
        do {
            cout << "\nStack using One Queue\n";
            cout << "1.Push\n2.Pop\n3.Top\n4.Display\n5.Exit\n";
            cin >> choice;
            switch(choice) {
                case 1: { int val; cout << "Enter value: "; cin >> val; S = push(S,val); break; }
                case 2: S = pop(S); break;
                case 3: cout << "Top element: " << top(S) << endl; break;
                case 4: display(S); break;
            }
        } while(choice != 5);
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
