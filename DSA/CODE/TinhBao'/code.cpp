#include<iostream>
using namespace std ;
struct Node {
    string info;
    Node* left;
    Node* right;
};

struct Tree {
    Node* root;
};

void CreateTree(Tree& t) {
    t.root = NULL;
}

Node* createNode(string x) {
    Node* node = new Node;
    node->info = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insertNode(Node*& root, string x) {
    if (root == NULL) {
        root = createNode(x);
        return;
    }
    if (x < root->info) {
        insertNode(root->left, x);
    }
    else {
        insertNode(root->right, x);
    }
}

void deleteNode(Node*& root, string x) {
    if (root == NULL) {
        return;
    }
    if (x < root->info) {
        deleteNode(root->left, x);
    }
    else if (x > root->info) {
        deleteNode(root->right, x);
    }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            root = temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            root = temp;
        }
        else {
            Node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->info = temp->info;
            deleteNode(root->right, temp->info);
        }
    }
}

Node* searchNode(Node* root, string x) {
    if (root == NULL) {
        return NULL;
    }
    if (root->info == x) {
        return root;
    }
    if (x < root->info) {
        return searchNode(root->left, x);
    }
    return searchNode(root->right, x);
}

bool isExist(Tree t, string x) {
    return searchNode(t.root, x) != NULL;
}

void TinhBao() {
    Tree t;
    CreateTree(t);
    int n;
    string x;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        if (n == 1) {
            cin >> x;
            if (searchNode(t.root, x) != NULL) {
                continue;
            }
            insertNode(t.root, x);
        }
        if (n == 3) {
            cin >> x;
            if (isExist(t, x) == 0) {
                continue;
            }
            deleteNode(t.root, x);
        }
        if (n == 2) {
            cin >> x;
            if (isExist(t, x)) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }
}

int main() {
    Tree t;
    TinhBao();
    return 0;
}
