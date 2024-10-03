#include <bits/stdc++.h>
using namespace std;

int ring[15];

// mode1: hook, mode2 remove
void recur(int i, int mode) {
  if (mode == 1 && ring[i]) return;
  if (mode == 2 && !ring[i]) return;
  if (i == 1) {
    if (mode == 1) {
      cout << "Move ring 1 in\n";
      ring[i] = 1;
    } else {
      cout << "Move ring 1 out\n";
      ring[i] = 0;
    }
    return;
  }
  if (!ring[i - 1]) recur(i - 1, 1);
  for (int j = i - 2; j >= 1; j--)
    recur(j, 2);
  cout << "Move ring " << i;
  if (mode == 1) {
    cout << " in\n";
    ring[i] = 1;
  } else {
    cout << " out\n";
    ring[i] = 0;
  }
  return;
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    ring[i] = 1;
  for (int i = n; i >= 1; i--)
    recur(i, 2);
}