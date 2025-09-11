#include <bits/stdc++.h>
using namespace std;

const int MAXLEN = 100;

typedef struct {
    int element[MAX];
    int front, rear;
} CQueue;

CQueue init(CQueue Q) {
    Q.front = Q.rear = -1;
    return Q;
}

int isEmpty(CQueue Q) {
    return (Q.front == -1);
}

int isFull(CQueue Q) {
    return (Q.front == (Q.rear + 1) % MAX);
}

CQueue enqueue(CQueue Q, int ITEM) {
    if (isFull(Q)) {
        cout << "Overflow" << endl;
    } else {
        if (Q.front == -1) { 
            Q.front = 0;
        }
        Q.rear = (Q.rear + 1) % MAX;
        Q.element[Q.rear] = ITEM;
    }
    return Q;
}

CQueue dequeue(CQueue Q) {
    if (isEmpty(Q)) {
        cout << "Underflow" << endl;
    } else {
        int ITEM = Q.element[Q.front];
        cout << "Dequeued: " << ITEM << endl;

        if (Q.front == Q.rear) {
            Q.front = Q.rear = -1;
        } else {
            Q.front = (Q.front + 1) % MAX;
        }
    }
    return Q;
}

int peek(CQueue Q) {
    if (isEmpty(Q)) {
        cout << "Underflow" << endl;
        return -1;
    }
    return Q.element[Q.front];
}

void display(CQueue Q) {
    if (isEmpty(Q)) {
        cout << "Underflow" << endl;
    } else {
        cout << "Queue: ";
        int i = Q.front;
        while (true) {
            cout << Q.element[i] << " ";
            if (i == Q.rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
}

int main() {
    CQueue Q;
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
                cout << "front element: " << peek(Q) << endl;
                break;
            }
        }
    } while (choice != 7);

    return 0;
}
