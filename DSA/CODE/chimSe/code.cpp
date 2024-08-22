#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

struct chimSe {
  string mauSac;
  double canNang;
  int tuoi;
};

void insertatKindex(chimSe s[], int &n, int k, chimSe x) {
  for (int i = n; i > k; i--) {
    s[i] = s[i - 1];
  }
  s[k] = x;
  n++;
}

void deleteatKindex(chimSe s[], int &n, int k) {
  for (int i = k; i < n - 1; i++) {
    s[i] = s[i + 1];
  }
  n--;
}

int findPosition(chimSe s[], int n, string mauSac, double canNang, int tuoi) {
  for (int i = 0; i < n; i++) {
    if (s[i].mauSac == mauSac && s[i].canNang == canNang && s[i].tuoi == tuoi) {
      return i;
    }
  }
  return -1;
}

void insertionSortbycanNang(chimSe s[], int n) {
  for (int i = 1; i < n; i++) {
    chimSe key = s[i];
    int j = i - 1;
    while (j >= 0 && s[j].canNang > key.canNang) {
      s[j + 1] = s[j];
      j = j - 1;
    }
    s[j + 1] = key;
  }
}

int main() {
  chimSe s[1000];
  int a, b;
  int n = 0;
  for (int i = 0; 1; i++) {
    cin >> s[i].mauSac;
    if (s[i].mauSac == "-1")
      break;
    else {
      cin >> s[i].canNang;
      cin >> s[i].tuoi;
      n++;
    }
  }
  while (cin >> a && a != -1) {
      cin >> b;
    if (a == 0) {
      chimSe x;
      cin >> x.mauSac;
      cin >> x.canNang;
      cin >> x.tuoi;
      insertatKindex(s, n, b, x);
    } else {
      deleteatKindex(s, n, b);
    }
  }
  chimSe x;
  cin >> x.mauSac;
  cin >> x.canNang;
  cin >> x.tuoi;
  if (findPosition(s, n, x.mauSac, x.canNang, x.tuoi) != -1)
    cout << findPosition(s, n, x.mauSac, x.canNang, x.tuoi) << endl;
  else
    cout << "da bay di" << endl;
  insertionSortbycanNang(s, n);
  for (int i = 0; i < n; i++) {
    cout << s[i].mauSac << " " << s[i].canNang << " " << s[i].tuoi << endl;
  }
  if (findPosition(s, n, x.mauSac, x.canNang, x.tuoi) != -1)
    cout << findPosition(s, n, x.mauSac, x.canNang, x.tuoi) << endl;
  else
    cout << "da bay di" << endl;
  return 0;
}