#include <bits/stdc++.h>
using namespace std;

const int MAXLEN = 100;

typedef struct {
    char element[MAXLEN];
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

Queue enqueue(Queue Q, char x) {
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

Queue dequeue(Queue Q, char &item) {
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

char peek(Queue Q) {
    if (isEmpty(Q)) return '\0';
    return Q.element[Q.front];
}

void firstNonRepeating(string str) {
    Queue Q;
    Q = init(Q);

    int freq[256] = {0};

    for (char ch : str) {
        if (ch == ' ') continue; 

        freq[(int)ch]++;

        Q = enqueue(Q, ch);

        while (!isEmpty(Q) && freq[(int)peek(Q)] > 1) {
            char temp;
            Q = dequeue(Q, temp);
        }

        // print result
        if (isEmpty(Q))
            cout << -1 << " ";
        else
            cout << peek(Q) << " ";
    }
    cout << endl;
}

int main() {
    string input = "a a b c"; 
    cout << "Input: " << input << endl;
    cout << "Output: ";
    firstNonRepeating(input);
    return 0;
}
