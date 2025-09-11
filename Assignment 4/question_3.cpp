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

bool isEmpty(Queue Q) {
    return (Q.front == -1);
}

bool isFull(Queue Q) {
    return (Q.rear == MAXLEN - 1);
}

Queue enqueue(Queue Q, int x) {
    if (isFull(Q)) {
        cout << "Overflow" << endl;
    } else {
        if (isEmpty(Q)) {
            Q.front = 0;
        }
        Q.rear++;
        Q.element[Q.rear] = x;
    }
    return Q;
}

Queue dequeue(Queue Q, int &item) {
    if (isEmpty(Q)) {
        cout << "Underflow" << endl;
    } else {
        item = Q.element[Q.front];
        if (Q.front == Q.rear) {
            Q.front = Q.rear = -1;
        } else {
            Q.front++;
        }
    }
    return Q;
}

void display(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Empty" << endl;
    } else {
        for (int i = Q.front; i <= Q.rear; i++) {
            cout << Q.element[i] << " ";
        }
        cout << endl;
    }
}

Queue interleave(Queue Q) {
    if (isEmpty(Q)) return Q;

    int n = Q.rear - Q.front + 1;
    if (n % 2 != 0) {
        cout << "Queue has odd number of elements, cannot interleave!" << endl;
        return Q;
    }

    int half = n / 2;

    int temp[MAXLEN], idx = 0;
    for (int i = 0; i < half; i++) {
        temp[idx++] = Q.element[Q.front + i];
    }

    Queue newQ = init(newQ);
    int i = 0, j = half;
    while (i < half && j < n) {
        newQ = enqueue(newQ, temp[i++]);  
        newQ = enqueue(newQ, Q.element[Q.front + j++]); 
    }

    return newQ;
}

int main() {
    Queue Q;
    Q = init(Q);

    int input[] = {4, 7, 11, 20, 5, 9};
    int n = 6;

    for (int i = 0; i < n; i++) {
        Q = enqueue(Q, input[i]);
    }

    cout << "Original Queue: ";
    display(Q);

    Q = interleave(Q);

    cout << "Interleaved Queue: ";
    display(Q);

    return 0;
}
