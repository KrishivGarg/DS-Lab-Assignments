#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }

    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node* convertArrToDLL(char arr[], int n) {
    Node* head = new Node(arr[0]);
    Node* back = head;
    for (int i = 1; i < n; i++) {
        Node* newNode = new Node(arr[i], nullptr, back);
        back->next = newNode;
        back = newNode;
    }
    return head;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL)
        return true;

    Node* left = head;
    Node* right = head;

    while (right->next != NULL)
        right = right->next;

    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    char arr[] = {'L', 'E', 'V', 'E', 'L'};
    Node* head = convertArrToDLL(arr, 5);
    print(head);
    cout << (isPalindrome(head) ? "Is Palindrome" : "Not a Palindrome");
    return 0;
}
