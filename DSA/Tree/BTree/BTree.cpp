#include <iostream>
#include<cstdlib>
using namespace std;


// Định nghĩa số lượng khóa tối đa trong một nút
#define MAX 3

// Cấu trúc của một nút trong B-Tree
struct BTreeNode {
    int *keys;   // Mảng lưu trữ các khóa
    BTreeNode **C; // Mảng con trỏ tới các nút con
    int n;      // Số lượng khóa hiện tại trong nút
    bool leaf;  // Biến để kiểm tra nút lá hay không

    // Hàm tạo cho một nút mới
    BTreeNode(bool leaf, int t);
    
    // Hàm chèn khóa vào nút không đầy đủ
    void insertNonFull(int k, int t);
    
    // Hàm tách nút con `i` của nút này
    void splitChild(int i, BTreeNode *y, int t);
    
    // Hàm duyệt các nút trong cây B-Tree
    void traverse();
    
    // Hàm tìm kiếm một khóa trong cây B-Tree
    BTreeNode *search(int k);

    friend class BTree;
};

// Cấu trúc của một B-Tree
class BTree {
    BTreeNode *root; // Con trỏ đến nút gốc
    int t;           // Bậc của cây B-Tree

public:
    // Hàm tạo cho cây B-Tree
    BTree(int _t) {
        root = nullptr;
        t = _t;
    }

    // Hàm duyệt cây B-Tree
    void traverse() {
        if (root != nullptr)
            root->traverse();
    }

    // Hàm tìm kiếm một khóa trong cây B-Tree
    BTreeNode* search(int k) {
        return (root == nullptr) ? nullptr : root->search(k);
    }

    // Hàm chèn một khóa vào cây B-Tree
    void insert(int k);
};

// Hàm tạo cho một nút mới trong B-Tree
BTreeNode::BTreeNode(bool leaf1, int t) {
    leaf = leaf1;
    keys = new int[2 * t - 1];
    C = new BTreeNode *[2 * t];
    n = 0;
}

// Hàm duyệt các nút trong cây B-Tree
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        // Nếu nút này không phải là nút lá, duyệt cây con trước
        if (!leaf)
            C[i]->traverse();
        cout << " " << keys[i];
    }
    
    // Duyệt cây con cuối cùng
    if (!leaf)
        C[i]->traverse();
}

// Hàm tìm kiếm một khóa trong cây B-Tree
BTreeNode* BTreeNode::search(int k) {
    int i = 0;
    while (i < n && k > keys[i])
        i++;
    
    if (keys[i] == k)
        return this;

    if (leaf)
        return nullptr;

    return C[i]->search(k);
}

// Hàm chèn một khóa vào cây B-Tree
void BTree::insert(int k) {
    if (root == nullptr) {
        root = new BTreeNode(true, t);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2 * t - 1) {
            BTreeNode *s = new BTreeNode(false, t);
            s->C[0] = root;
            s->splitChild(0, root, t);
            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k, t);
            root = s;
        } else
            root->insertNonFull(k, t);
    }
}

// Hàm chèn khóa vào nút không đầy đủ
void BTreeNode::insertNonFull(int k, int t) {
    int i = n - 1;
    if (leaf) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        n = n + 1;
    } else {
        while (i >= 0 && keys[i] > k)
            i--;
        if (C[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, C[i + 1], t);
            if (keys[i + 1] < k)
                i++;
        }
        C[i + 1]->insertNonFull(k, t);
    }
}

// Hàm tách nút con `y` của nút này
void BTreeNode::splitChild(int i, BTreeNode *y, int t) {
    BTreeNode *z = new BTreeNode(y->leaf, t);
    z->n = t - 1;
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];
    if (!y->leaf) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }
    y->n = t - 1;
    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];
    C[i + 1] = z;
    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];
    keys[i] = y->keys[t - 1];
    n = n + 1;
}


// Hàm xóa một khóa khỏi cây B-Tree
void BTree::remove(int k) {
    if (root == nullptr) {
        cout << "Cây B-Tree rỗng.\n";
        return;
    }
    
    root->remove(k);
    
    // Nếu nút gốc không còn khóa, cập nhật lại nút gốc
    if (root->n == 0) {
        BTreeNode *tmp = root;
        if (root->leaf)
            root = nullptr;
        else
            root = root->C[0];
        delete tmp;
    }
}

// Hàm xóa một khóa khỏi nút
void BTreeNode::remove(int k) {
    int idx = findKey(k);
    
    // Nếu khóa k có trong nút hiện tại
    if (idx < n && keys[idx] == k) {
        if (leaf)
            removeFromLeaf(idx);
        else
            removeFromNonLeaf(idx);
    } else {
        // Nếu nút hiện tại là nút lá
        if (leaf) {
            cout << "Khóa " << k << " không tồn tại trong cây B-Tree.\n";
            return;
        }
        
        // Kiểm tra xem khóa k có trong nút con cuối cùng không
        bool flag = (idx == n);
        
        // Nếu nút con chứa khóa k có ít nhất t khóa
        if (C[idx]->n >= t)
            fill(idx);
        
        // Nếu nút con cuối cùng đã được gộp, điều chỉnh chỉ số
        if (flag && idx > n)
            C[idx - 1]->remove(k);
        else
            C[idx]->remove(k);
    }
}

// Hàm xóa một khóa khỏi nút
void BTreeNode::remove(int k) {
    int idx = findKey(k);
    
    // Nếu khóa k có trong nút hiện tại
    if (idx < n && keys[idx] == k) {
        if (leaf)
            removeFromLeaf(idx);
        else
            removeFromNonLeaf(idx);
    } else {
        // Nếu nút hiện tại là nút lá
        if (leaf) {
            cout << "Khóa " << k << " không tồn tại trong cây B-Tree.\n";
            return;
        }
        
        // Kiểm tra xem khóa k có trong nút con cuối cùng không
        bool flag = (idx == n);
        
        // Nếu nút con chứa khóa k có ít nhất t khóa
        if (C[idx]->n < t)
            fill(idx);
        
        // Nếu nút con cuối cùng đã được gộp, điều chỉnh chỉ số
        if (flag && idx > n)
            C[idx - 1]->remove(k);
        else
            C[idx]->remove(k);
    }
}

// Hàm tìm vị trí của khóa trong nút
int BTreeNode::findKey(int k) {
    int idx = 0;
    while (idx < n && keys[idx] < k)
        ++idx;
    return idx;
}

// Hàm xóa khóa khỏi nút lá
void BTreeNode::removeFromLeaf(int idx) {
    for (int i = idx + 1; i < n; ++i)
        keys[i - 1] = keys[i];
    --n;
}

// Hàm xóa khóa khỏi nút không phải lá
void BTreeNode::removeFromNonLeaf(int idx) {
    int k = keys[idx];
    
    // Nếu nút con trước nút chứa khóa k có ít nhất t khóa
    if (C[idx]->n >= t) {
        int pred = getPred(idx);
        keys[idx] = pred;
        C[idx]->remove(pred);
    }
    // Nếu nút con sau nút chứa khóa k có ít nhất t khóa
    else if (C[idx + 1]->n >= t) {
        int succ = getSucc(idx);
        keys[idx] = succ;
        C[idx + 1]->remove(succ);
    }
    // Nếu cả hai nút con trước và sau đều có ít hơn t khóa
    else {
        merge(idx);
        C[idx]->remove(k);
    }
}

// Hàm lấy khóa trước khóa tại vị trí idx trong nút
int BTreeNode::getPred(int idx) {
    BTreeNode *cur = C[idx];
    while (!cur->leaf)
        cur = cur->C[cur->n];
    return cur->keys[cur->n - 1];
}

// Hàm lấy khóa sau khóa tại vị trí idx trong nút
int BTreeNode::getSucc(int idx) {
    BTreeNode *cur = C[idx + 1];
    while (!cur->leaf)
        cur = cur->C[0];
    return cur->keys[0];
}

// Hàm điền vào nút con tại vị trí idx nếu nút con đó có ít hơn t khóa
void BTreeNode::fill(int idx) {
    // Nếu nút con trước nút con đó có ít nhất t khóa
    if (idx != 0 && C[idx - 1]->n >= t)
        borrowFromPrev(idx);
    // Nếu nút con sau nút con đó có ít nhất t khóa
    else if (idx != n && C[idx + 1]->n >= t)
        borrowFromNext(idx);
    // Nếu cả hai nút con trước và sau đều có ít hơn t khóa
    else {
        // Gộp nút con và nút con sau
        if (idx != n)
            merge(idx);
        // Gộp nút con và nút con trước
        else
            merge(idx - 1);
    }
}

// Hàm mượn khóa từ nút con trước nút con tại vị trí idx
void BTreeNode::borrowFromPrev(int idx) {
    BTreeNode *child = C[idx];
    BTreeNode *sibling = C[idx - 1];
    
    // Di chuyển tất cả các khóa trong nút con sang phải
    for (int i = child->n - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];
    
    // Di chuyển tất cả các con trỏ trong nút con sang phải
    if (!child->leaf) {
        for (int i = child->n; i >= 0; --i)
            child->C[i + 1] = child->C[i];
    }
    
    // Gán khóa đầu tiên của nút con trước vào nút con
    child->keys[0] = keys[idx - 1];
    
    // Di chuyển con trỏ cuối cùng của nút con trước vào nút con
    if (!child->leaf)
        child->C[0] = sibling->C[sibling->n];
    
    // Di chuyển khóa cuối cùng của nút con trước vào nút hiện tại
    keys[idx - 1] = sibling->keys[sibling->n - 1];
    
    // Cập nhật số lượng khóa trong nút con và nút con trước
    child->n += 1;
    sibling->n -= 1;
}

// Hàm mượn khóa từ nút con sau nút con tại vị trí idx
void BTreeNode::borrowFromNext(int idx) {
    BTreeNode *child = C[idx];
    BTreeNode *sibling = C[idx + 1];
    
    // Gán khóa cuối cùng của nút con vào nút con
    child->keys[child->n] = keys[idx];
    
    // Di chuyển con trỏ đầu tiên của nút con sau vào nút con
    if (!child->leaf)
        child->C[child->n + 1] = sibling->C[0];
    
    // Gán khóa đầu tiên của nút con sau vào nút hiện tại
    keys[idx] = sibling->keys[0];
    
    // Di chuyển tất cả các khóa trong nút con sau sang trái
    for (int i = 1; i < sibling->n; ++i)
        sibling->keys[i - 1] = sibling->keys[i];
    
    // Di chuyển tất cả các con trỏ trong nút con sau sang trái
    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; ++i)
            sibling->C[i - 1] = sibling->C[i];
    }
    
    // Cập nhật số lượng khóa trong nút con và nút con sau
    child->n += 1;
    sibling->n -= 1;
}

// Hàm gộp nút con tại vị trí idx với nút con sau
void BTreeNode::merge(int idx) {
    BTreeNode *child = C[idx];
    BTreeNode *sibling = C[idx + 1];
    
    // Gán khóa tại vị trí idx vào nút con
    child->keys[t - 1] = keys[idx];
    
    // Sao chép khóa từ nút con sau vào nút con
    for (int i = 0; i < sibling->n; ++i)
        child->keys[i + t] = sibling->keys[i];
    
    // Sao chép con trỏ từ nút con sau vào nút con
    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; ++i)
            child->C[i + t] = sibling->C[i];
    }   
    
    // Di chuyển tất cả các khóa trong nút hiện tại sang trái
    for (int i = idx + 1; i < n; ++i)
        keys[i - 1] = keys[i];
    
    // Di chuyển tất cả các con trỏ trong nút hiện tại sang trái
    for (int i = idx + 2; i <= n; ++i)
        C[i - 1] = C[i];
    
    // Cập nhật số lượng khóa trong nút con và nút hiện tại
    child->n += sibling->n + 1;
    n -= 1;
    
    // Xóa nút con sau
    delete sibling;
}
int main() {
    BTree t(3); // B-Tree với bậc t = 3
    t.insert(rand()%10);
    t.insert(rand()%100);
    t.insert(rand()%10);
    t.insert(rand()%100);
    t.insert(rand()%100);
    t.insert(rand()%100);
    t.insert(rand()%100);
    t.insert(rand()%100);

    cout << "Duyệt cây B-Tree:\n";
    t.traverse();

    int key = 6;
    if (t.search(key) != nullptr)
        cout << "\nKhóa " << key << " được tìm thấy trong cây B-Tree\n";
    else
        cout << "\nKhóa " << key << " không được tìm thấy trong cây B-Tree\n";

    return 0;
}