#include<bits/stdc++.h>
using namespace std ;
using ll = long long;
struct candy {
  string color;
  string flavour;
  double weight;
  string shape;
};

void insertionSort(candy k[], int n) {
  for (int i = 1; i < n; i++) {
    candy key = k[i];
    int j = i - 1;
    while (j >= 0 && key.weight < k[j].weight) {
      k[j + 1] = k[j];
      j--;
    }
    k[j + 1] = key;
  }
}
int main() {
  candy k[10000];
  string a;
  int i = 0;
  while (cin >> k[i].color && k[i].color != "-1") {
    cin >> k[i].flavour;
    cin >> k[i].shape;
    cin >> k[i].weight;
    i++;
  }
  int x;
  cin >> x;
  candy k2[10000];
  copy(k, k + i, k2);
  insertionSort(k2, i);
  candy tmp = k2[x];

  for (int c = 0; c <= i; c++) {
    if (k[c].color == tmp.color && k[c].flavour == tmp.flavour &&
        k[c].shape == tmp.shape ) {
      cout << k[c].color << " " << k[c].flavour << " " << k[c].shape << " "
           << k[c].weight << endl;
    }
  }

  return 0;
}