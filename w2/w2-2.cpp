#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int t, n;
int x;
int len;
vector<int> res;
set<string> ans;

void dfs(int i, int sum) {
  if (sum > t) return;
  if (sum == t) {
    // cout << "equa " ;
    string equation;
    for (auto v : res) {
      if (equation != "") equation += '+';
      equation += to_string(v);
    }
    equation += "\n";
    // cout << equation;
    ans.insert(equation);
    return;
  }
  if (i >= len) return;

  // Choose
  res.push_back(a[i]);
  dfs(i + 1, sum + a[i]);
  res.pop_back();
  // Not choose
  dfs(i + 1, sum);
}

int main() {
  cin >> t;
  while (t > 0) {
    cin >> n;
    if (!n) break;
    for (int i = 0; i < n; i++) {
      cin >> x;
      if (x > t) continue;
      a.push_back(x);
    }
    len = a.size();
    dfs(0, 0);
    cout << "Sums of " << t << ":\n";
    if (ans.empty())
      cout << "NONE\n";
    else {
      for (auto it = ans.rbegin() ; it != ans.rend() ; it++)
        cout << *it;
    }
    a.clear();
    res.clear();
    ans.clear();
    cin >> t;
  }
}