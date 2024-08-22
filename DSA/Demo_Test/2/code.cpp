#include <bits/stdc++.h>


using namespace std;

struct Point {
    double x, y, z;
};

bool comparePoints(const Point& p1, const Point& p2) {
    if (p1.x != p2.x) {
        return p1.x < p2.x;
    } else if (p1.y != p2.y) {
        return p1.y < p2.y;
    } else {
        return p1.z < p2.z;
    }
}

int binarySearch(const Point* arr, int n, const Point& target) {
    int left = 0;
    int right = n - 1;
    int steps = 0;
    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;
        if (comparePoints(arr[mid], target)) {
            left = mid + 1;
        } else if (comparePoints(target, arr[mid])) {
            right = mid - 1;
        } else {
            return steps; 
        }
    }
    return -1; 
}


int main() {
    int n, m;
    cin >> n;
    Point* A = new Point[n];
    for (int i = 0; i < n; ++i) {
        cin >> A[i].x >> A[i].y >> A[i].z;
    }

    
    sort(A, A + n, comparePoints);

    cin >> m;
    for (int i = 0; i < m; ++i) {
        Point pi;
        cin >> pi.x >> pi.y >> pi.z;
        int steps = binarySearch(A, n, pi);
        if (steps != -1) {
            cout << steps << endl;
        } else {
            cout << "KHONG" << endl;
        }
    }

    delete[] A;
    return 0;
}

