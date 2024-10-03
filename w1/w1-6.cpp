#include <bits/stdc++.h>
using namespace std;

int t, n;
int row, col, num;
set<int> ans;
set<int> res;
int mn = INT_MAX;
int ni, nj;
vector<pair<int, int>> vt;

int cal() {
  int sum = 0;
  for (auto p : vt) {
    int x = p.first / 5;
    int y = p.first % 5;
    int val = p.second;
    int dis = INT_MAX;
    for (auto office : res) {
      dis = min(dis, abs(x - office / 5) + abs(y - office % 5));
    }
    sum += dis * val;
  }
  return sum;
}

void dfs(int idx, int cnt) {
  if (cnt == 5) {
    int val = cal();
    if (val < mn) {
      mn = val;
      ans = res;
    }
    return;
  }
  if (idx >= 25) return;
  res.insert(idx);
  dfs(idx + 1, cnt + 1);
  res.erase(idx);
  dfs(idx + 1, cnt);
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> row >> col >> num;
      vt.push_back({row * 5 + col, num});
    }
    dfs(0, 0);
    for (auto it = ans.begin(); it != ans.end(); it++) {
      if (it != ans.begin()) cout << " ";
      cout << *it;
    }
    cout << "\n";

    vt.clear();
    mn = INT_MAX;
    ans.clear();
    res.clear();
  }
}