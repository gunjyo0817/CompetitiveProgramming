#include <bits/stdc++.h>
using namespace std;

int n, sum;
vector<int> a(20);
vector<int> sides(4, 0);

int target;

bool dfs(int i) {
  if (i == n) {
    for (auto v : sides) {
      if (v != target) return false;
    }
    return true;
  }

  for (int j = 0; j < 4; j++) {
    if (a[i] + sides[j] > target) continue;

    sides[j] += a[i];
    if (dfs(i + 1)) return true;

    sides[j] -= a[i];
    if (!sides[j]) return false;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    sides = vector<int>(4, 0);
    cin >> n;
    a.resize(n);
    sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum % 4) {
      cout << "no\n";
      continue;
    }
    sort(a.rbegin(), a.rend());
    target = sum / 4;
    if (target < a[0]) {
      cout << "no\n";
      continue;
    }
    cout << (dfs(0) ? "yes\n" : "no\n");
  }
}