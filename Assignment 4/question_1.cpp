#include <bits/stdc++.h>
using namespace std;

const int MAXLEN = 100;

typedef struct {
    int element[MAXLEN];
    int front, rear;
} Queue;

Queue init(Queue Q) {
    Q.front = Q.rear = -1;
    return Q;
}

int isEmpty(Queue Q) {
    return (Q.front == -1 || Q.front > Q.rear);
}

int isFull(Queue Q) {
    return (Q.rear == MAXLEN - 1);
}

Queue enqueue(Queue Q, int x) {
    if (isFull(Q)) {
        cout << "Overflow" << endl;
    } else if (isEmpty(Q)) {
        Q.front = Q.rear = 0;
        Q.element[Q.rear] = x;
    } else {
        Q.rear++;
        Q.element[Q.rear] = x;
    }
    return Q;
}

Queue dequeue(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Underflow" << endl;
    } else {
        cout << "Dequeued: " << Q.element[Q.front] << endl;
        Q.front++;
    }
    return Q;
}

int peek(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Underflow" << endl;
        return -1;
    }
    return Q.element[Q.front];
}

void display(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Underflow" << endl;
    } else {
        cout << "Queue: ";
        for (int i = Q.front; i <= Q.rear; i++) {
            cout << Q.element[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Queue Q;
    Q = init(Q);
    int choice;

    do {
        cout << "\nEnter choice :" << endl;
        cout << "1. enqueue()" << endl;
        cout << "2. dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. display()" << endl;
        cout << "6. peek()" << endl;
        cout << "7. exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter value to enqueue: ";
                int val;
                cin >> val;
                Q = enqueue(Q, val);
                break;
            }
            case 2: {
                Q = dequeue(Q);
                break;
            }
            case 3: {
                cout << (isEmpty(Q) ? "Empty" : "Not empty") << endl;
                break;
            }
            case 4: {
                cout << (isFull(Q) ? "Full" : "Not full") << endl;
                break;
            }
            case 5: {
                display(Q);
                break;
            }
            case 6: {
                cout << "Front element: " << peek(Q) << endl;
                break;
            }
        }
    } while (choice != 7);

    return 0;
}
