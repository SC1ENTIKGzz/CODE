#include <iostream>
#include<bits/stdc++.h>

using namespace std ;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // addFirst a new node at the beginning of the list
    void addFirst(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    // add a new node at the last of the list
    void addTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    // add a new node at the given position
    void addAt(int position, int value) {
        Node* newNode = new Node(value);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* current = head;
        for (int i = 0; i < position - 1; i++) {
            if (current == nullptr) {
                cout << "Position out of range" << endl;
                return;
            }
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Position out of range" << endl;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    // remove the first node of the list
    void removeFirst() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    // remove the last node of the list
    void removeLast() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    // remove the node at the given position
    
    void removeAt(int position) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        for (int i = 0; i < position - 1; i++) {
            if (current == nullptr) {
                cout << "Position out of range" << endl;
                return;
            }
            current = current->next;
        }
        if (current == nullptr || current->next == nullptr) {
            cout << "Position out of range" << endl;
            return;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Display the elements of the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    LinkedList myList;
    myList.addFirst(1);
    myList.addFirst(2);
    myList.addFirst(3);
    myList.addTail(4);
    myList.addTail(5);
    myList.addAt(2, 6);
    myList.display();
    myList.removeFirst();
    myList.removeLast();
    myList.removeAt(2);
    myList.display();



    return 0;
}