#include <bits/stdc++.h>
using namespace std;

int n;
int sum = 0;
string s;
set<string> res;

void dfs(int i) {
  if (i == n) {
    sum++;
    res.insert(s);
    return;
  }
  vector<bool> used(30, false);
  for (int j = i; j < n; j++) {
    if (used[s[j] - 'a']) continue;
    used[s[j] - 'a'] = true;
    swap(s[i], s[j]);
    dfs(i + 1);
    swap(s[i], s[j]);
  }
}

int main() {
  cin >> s;
  sort(s.begin(), s.end());
  n = s.length();
  dfs(0);
  cout << res.size() << "\n";
  for (auto i : res)
    cout << i << "\n";
}