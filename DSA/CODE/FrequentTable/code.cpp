#include<iostream>
using namespace std ;
struct Node {
    int data;
    int count;
    Node* next;
};

Node* insert(Node* head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->count = 1;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* current = head;
    Node* prev = NULL;
    while (current != NULL && current->data < data) {
        prev = current;
        current = current->next;
    }

    if (current != NULL && current->data == data) {
        current->count++;
        delete newNode;
    } else {
        newNode->next = current;
        if (prev == NULL) {
            head = newNode;
        } else {
            prev->next = newNode;
        }
    }

    return head;
}

void print(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " " << current->count << endl;
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    int data;
    cin >> data;
    while (data != 0) {
        head = insert(head, data);
        cin >> data;
    }

    print(head);

    return 0;
}