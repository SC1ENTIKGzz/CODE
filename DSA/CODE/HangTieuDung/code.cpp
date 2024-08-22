#include <iostream>
using namespace std ;

struct Product {
    string type;
    string batchCode;
    string productCode;

    int nhap() {
        cin >> type;
        if (type == "-1")
            return -1;
        cin >> batchCode >> productCode;
        return 1;
    }

    void xuat() const {
        cout << type << " " << batchCode << " " << productCode << endl;
    }
};

struct Dai_Ly {
    string s;
    int n;

    void nhap() {
        cin >> s >> n;
    }

    void xuat() const {
        cout << s << " " << n << " ";
    }
};

struct Node {
    Product data;
    Node* pNext;

    Node(Product a) : data(a), pNext(nullptr) {}
};

struct DLNode {
    Dai_Ly Du_Lieu;
    Product data;
    DLNode* pNext1;

    DLNode(Dai_Ly a, Product b) : Du_Lieu(a), data(b), pNext1(nullptr) {}
};

struct List {
    Node* pHead;
    Node* pTail;

    List() : pHead(nullptr), pTail(nullptr) {}
};

struct ListDL {
    DLNode* pHead1;
    DLNode* pTail1;

    ListDL() : pHead1(nullptr), pTail1(nullptr) {}
};

void Add_Head(List& l, Node* p) {
    if (l.pHead == nullptr) {
        l.pHead = p;
        l.pTail = l.pHead;
    } else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void Add_Tail(List& l, Node*p)
{
    if (l.pHead == nullptr) {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else
    {
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void Add_HeadDL(ListDL& DL, DLNode* cur) {
    if (DL.pHead1 == nullptr) {
        DL.pHead1 = cur;
        DL.pTail1 = DL.pHead1;
    } else {
        cur->pNext1 = DL.pHead1;
        DL.pHead1 = cur;
    }
}
void Add_TailDL(ListDL& DL, DLNode* cur)
{
    if (DL.pHead1 == nullptr) {
        DL.pHead1 = cur;
        DL.pTail1 = DL.pHead1;
    }
    else
    {
        DL.pTail1->pNext1=cur;
        DL.pTail1=cur;
    }
}

int Remove_Head(List& l, Product& x) {
    if (l.pHead == nullptr)
        return 0;
    Node* p = l.pHead;
    l.pHead = l.pHead->pNext;
    if (l.pHead == nullptr)
        l.pTail = nullptr;
    x = p->data;
    delete p;
    return 1;
}

int Remove_Tail(List& l, Product& x) {
    if (l.pHead == nullptr)
        return 0;
    Node* p = l.pHead;
    Node* q = nullptr;
    while (p->pNext != nullptr) {
        q = p;
        p = p->pNext;
    }
    if (q != nullptr)
        q->pNext = nullptr;
    else
        l.pHead = nullptr;
    l.pTail = q;
    x = p->data;
    delete p;
    return 1;
}

void Print_List(const List& l) {
    Node* p = l.pHead;
    while (p != nullptr) {
        p->data.xuat();
        p = p->pNext;
    }
}

void Print_DL(const ListDL& DL) {
    if(DL.pHead1==NULL)
    {
        cout<<"\nkhong co luot xuat hang nao";
        return;
    }
    DLNode* cur = DL.pHead1;
    while (cur != nullptr) {
        cur->Du_Lieu.xuat();
        cur->data.xuat();
        cur = cur->pNext1;
    }
}

int main() {
    List l;
    ListDL DL;
    while (true) {
        Product tmp;
        if (tmp.nhap() == -1)
            break;
        Add_Tail(l, new Node(tmp));
    }

    while (true) {
        int option;
        cin >> option;
        if (option == -1)
            break;
        switch (option) {
            case 0: {
                Product tmp;
                if (tmp.nhap() != -1) {
                    Add_Tail(l, new Node(tmp));
                }
                break;
            }
            case 1: {
                Dai_Ly a;
                a.nhap();
                Product x;
                if (a.n > 50) {
                    if (Remove_Tail(l, x)) {
                        Add_TailDL(DL, new DLNode(a, x));
                    }
                } else {
                    if (Remove_Head(l, x)) {
                        Add_TailDL(DL, new DLNode(a, x));
                    }
                }
                break;
            }
        }
    }

    Print_List(l);
    Print_DL(DL);

    return 0;
}