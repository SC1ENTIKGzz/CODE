#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y, z;
    Point* next;
};

struct LinkedList {
    Point* head;
    Point* tail;
};

void addTail(LinkedList*& list, double x, double y, double z) {
    Point* newNode = new Point;
    newNode->x = x;
    newNode->y = y;
    newNode->z = z;
    newNode->next = nullptr;

    if (list->head == nullptr) {
        list->head = list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void findPoint(LinkedList* list, double x, double y, double z) {
    int index = 0;
    Point* current = list->head;
    while (current != nullptr) {
        if (current->x == x && current->y == y && current->z == z) {
            cout << index << endl;
            return;
        }
        current = current->next;
        index++;
    }
    cout << "KHONG" << endl;
}

void run() {
    int n, m;
    cin >> n;
    LinkedList* list = new LinkedList;
    list->head = list->tail = nullptr;
    for (int i = 0; i < n; i++) {
        double x, y, z;
        cin >> x >> y >> z;
        addTail(list, x, y, z);
    }
    cin >> m;
    for (int j = 0; j < m; j++) {
        double x, y, z;
        cin >> x >> y >> z;
        findPoint(list, x, y, z);
    }
    while (list->head != nullptr) {
        Point* temp = list->head;
        list->head = list->head->next;
        delete temp;
    }
    delete list;
}

int main() {
    int* a = new int[256];
    int* b = new int[256];
    delete[] a;
    run();
    delete[] b;
}
