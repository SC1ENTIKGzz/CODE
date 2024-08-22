#include <iostream>
using namespace std;

// Định nghĩa một nút trong cây nhị phân
struct TreeNode {
    int data;        // Dữ liệu của nút
    TreeNode* left;  // Con trỏ tới nút con trái
    TreeNode* right; // Con trỏ tới nút con phải

    // Hàm tạo cho một nút mới
    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Hàm duyệt theo kiểu Inorder (LNR) bằng thuật toán Morris
void morrisInorderTraversal(TreeNode* root) {
    TreeNode* current = root;
    while (current != nullptr) {
        if (current->left == nullptr) {
            cout << current->data << " ";
            current = current->right;
        } else {
            TreeNode* pre = current->left;
            while (pre->right != nullptr && pre->right != current) {
                pre = pre->right;
            }

            if (pre->right == nullptr) {
                pre->right = current;
                current = current->left;
            } else {
                pre->right = nullptr;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
    cout << endl;
}

// Hàm duyệt theo kiểu Preorder (NLR) bằng thuật toán Morris
void morrisPreorderTraversal(TreeNode* root) {
    TreeNode* current = root;
    while (current != nullptr) {
        if (current->left == nullptr) {
            cout << current->data << " ";
            current = current->right;
        } else {
            TreeNode* pre = current->left;
            while (pre->right != nullptr && pre->right != current) {
                pre = pre->right;
            }

            if (pre->right == nullptr) {
                cout << current->data << " ";
                pre->right = current;
                current = current->left;
            } else {
                pre->right = nullptr;
                current = current->right;
            }
        }
    }
    cout << endl;
}

// Hàm tạo một cây mẫu để kiểm tra
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();

    // Duyệt theo kiểu Inorder (LNR) bằng thuật toán Morris
    cout << "Duyệt theo kiểu Inorder (LNR) bằng thuật toán Morris: ";
    morrisInorderTraversal(root);

    // Duyệt theo kiểu Preorder (NLR) bằng thuật toán Morris
    cout << "Duyệt theo kiểu Preorder (NLR) bằng thuật toán Morris: ";
    morrisPreorderTraversal(root);

    return 0;
}
