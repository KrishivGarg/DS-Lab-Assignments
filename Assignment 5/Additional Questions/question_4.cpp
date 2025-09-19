#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val1, Node* next1) {
        val = val1;
        next = next1;
    }

    Node(int val1) {
        val = val1;
        next = nullptr;
    }
};

Node* insertAtEnd(Node* head, int data) {
    if (head == NULL) {
        return new Node(data);
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    Node* tail = new Node(data);
    temp->next = tail;
    return head;
}

void display(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

Node* findNthNode(Node* head, int n) {
    Node* temp = head;
    int cnt = 1;
    while (temp != NULL && cnt < n) {
        temp = temp->next;
        cnt++;
    }
    return temp;
}

Node* rotateLeft(Node* head, int k) {
    if (head == NULL || k == 0) return head;
    Node* tail = head;
    int length = 1;
    while (tail->next != NULL) {
        length++;
        tail = tail->next;
    }
    k = k % length;
    if (k == 0) return head;
    tail->next = head;
    Node* newLastNode = findNthNode(head, k);
    head = newLastNode->next;
    newLastNode->next = NULL;

    return head;
}

int main() {
    Node* head = nullptr;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: " << endl;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        head = insertAtEnd(head, arr[i]);
    }

    int k;
    cout << "Enter k : ";
    cin >> k;

    head = rotateLeft(head, k);

    cout << "Updated linked list after left rotation: " << endl;
    display(head);

    return 0;
}
