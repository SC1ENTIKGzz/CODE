#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y, z;
};

bool SoSanh(Point a, Point b) {
    if (a.x < b.x) {
        return true;
    }
    if (a.x == b.x && a.y > b.y) {
        return true;
    }
    if (a.x == b.x && a.y == b.y && a.z < b.z) {
        return true;
    }
    return false;
}

void Swap(Point &a, Point &b) {
    Point temp = a;
    a = b;
    b = temp;
}

int partition(vector<Point>& points, int low, int high) {
    Point pivot = points[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (SoSanh(points[j], pivot)) {
            i++;
            Swap(points[i], points[j]);
        }
    }
    Swap(points[i + 1], points[high]);
    return (i + 1);
}

void quickSort(vector<Point>& points, int low, int high) {
    if (low < high) {
        int pi = partition(points, low, high);
        quickSort(points, low, pi - 1);
        quickSort(points, pi + 1, high);
    }
}

int main() {
    int N;
    cin >> N;
    vector<Point> points(N);
    for (int i = 0; i < N; i++)
        cin >> points[i].x >> points[i].y >> points[i].z;

    quickSort(points, 0, N - 1);

    for (int i = 0; i < N; i++)
        cout << points[i].x << " " << points[i].y << " " << points[i].z << "\n";

    return 0;
}