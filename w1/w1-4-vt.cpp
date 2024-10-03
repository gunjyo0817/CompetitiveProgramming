#include <bits/stdc++.h>
using namespace std;

int n;
int pt = 0;
string s;
string ans;
vector<string> res;
vector<bool> used(10, false);

void dfs(int i) {
  if (i == n) {
    res.push_back(ans);
    return;
  }
  int pre = -1;
  for (int j = 0; j < n; j++) {
    if (used[j] || pre == s[j] - 'a') continue;
    used[j] = true;
    ans[pt++] = s[j];
    dfs(i + 1);
    used[j] = false;
    pt--;
    pre = s[j] - 'a';
  }
}

int main() {
  cin >> s;
  n = s.length();
  sort(s.begin(), s.end());
  ans = s;
  dfs(0);
  cout << res.size() << "\n";
  for (auto i : res)
    cout << i << "\n";
}