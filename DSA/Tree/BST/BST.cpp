#include <iostream>
using namespace std ;


struct Node {
    int data;       
    Node* left;    
    Node* right;   
    
  
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class BST {
private:
    Node* root; 


    Node* insertNode(Node* node, int data) {

        if (node == nullptr) {
            return new Node(data);
        }

  
        if (data < node->data) {
            node->left = insertNode(node->left, data);
        } else if (data > node->data) {
            node->right = insertNode(node->right, data);
        }


        return node;
    }

    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);      
            cout << node->data << " ";    
            inOrderTraversal(node->right);   
        }
    }

    Node* search(Node* node, int data) {
 
        if (node == nullptr || node->data == data) {
            return node;
        }


        if (node->data < data) {
            return search(node->right, data);
        }

        return search(node->left, data);
    }

public:

    BST() {
        root = nullptr;
    }

    void insert(int data) {
        root = insertNode(root, data);
    }


    void inOrder() {
        inOrderTraversal(root);
        cout << endl;
    }

    bool search(int data) {
        return search(root, data) != nullptr;
    }
};

int main() {
    BST tree;


    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);


    cout << "In-order traversal: ";
    tree.inOrder();


    int value = 40;
    if (tree.search(value)) {
        cout << value << " is found in the BST." << endl;
    } else {
        cout << value << " is not found in the BST." << endl;
    }

    return 0;
}
