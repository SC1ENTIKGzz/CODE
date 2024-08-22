#include <iostream>
using namespace std;

// Định nghĩa một nút trong danh sách liên kết đôi
struct Node {
    int data;     // Dữ liệu của nút
    Node* next;   // Con trỏ tới nút kế tiếp
    Node* prev;   // Con trỏ tới nút trước đó

    // Hàm tạo cho một nút mới
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Lớp danh sách liên kết đôi
class DoublyLinkedList {
private:
    Node* head;   // Con trỏ tới đầu của danh sách
    Node* tail;   // Con trỏ tới cuối của danh sách

public:
    // Hàm tạo cho danh sách liên kết đôi
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Hàm chèn một nút mới vào đầu danh sách
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Hàm chèn một nút mới vào cuối danh sách
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Hàm tìm kiếm một giá trị trong danh sách
    bool search(int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Hàm xóa một nút chứa giá trị nhất định
    void deleteNode(int val) {
        if (head == nullptr) return;

        Node* temp = head;
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }

        if (temp == nullptr) return;

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }

        delete temp;
    }

    // Hàm duyệt danh sách theo kiểu LNR (Inorder)
    void traverseLNR() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }

    // Hàm duyệt danh sách theo kiểu NLR (Preorder)
    void traverseNLR() {
        traverseNLRHelper(head);
        cout << "null" << endl;
    }

    // Hàm hỗ trợ đệ quy để duyệt theo kiểu NLR
    void traverseNLRHelper(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " -> ";
        traverseNLRHelper(node->next);
    }

    // Hàm duyệt danh sách theo kiểu LRN (Postorder)
    void traverseLRN() {
        traverseLRNHelper(head);
        cout << "null" << endl;
    }

    // Hàm hỗ trợ đệ quy để duyệt theo kiểu LRN
    void traverseLRNHelper(Node* node) {
        if (node == nullptr) return;
        traverseLRNHelper(node->next);
        cout << node->data << " -> ";
    }
    
};

int main() {
    DoublyLinkedList list;

    // Chèn các giá trị vào danh sách
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtHead(5);

    // Duyệt danh sách theo kiểu LNR (Inorder)
    cout << "Duyệt theo kiểu LNR (Inorder): ";
    list.traverseLNR();

    // Duyệt danh sách theo kiểu NLR (Preorder)
    cout << "Duyệt theo kiểu NLR (Preorder): ";
    list.traverseNLR();

    // Duyệt danh sách theo kiểu LRN (Postorder)
    cout << "Duyệt theo kiểu LRN (Postorder): ";
    list.traverseLRN();

    // Tìm kiếm một giá trị trong danh sách
    int valueToSearch = 20;
    if (list.search(valueToSearch)) {
        cout << valueToSearch << " được tìm thấy trong danh sách." << endl;
    } else {
        cout << valueToSearch << " không được tìm thấy trong danh sách." << endl;
    }

    // Xóa một giá trị trong danh sách
    list.deleteNode(10);
    cout << "Danh sách sau khi xóa 10: ";
    list.traverseLNR();

    return 0;
}
