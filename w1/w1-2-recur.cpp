#include <bits/stdc++.h>
using namespace std;

vector<string> genGrayCode(int n) {
  if (n == 1) return {"0", "1"};
  vector<string> pre = genGrayCode(n - 1);
  vector<string> res;
  for (auto v : pre)
    res.push_back("0" + v);
  for (auto v = pre.rbegin(); v != pre.rend(); v++)
    res.push_back("1" + (*v));
  return res;
}
int main() {
  int n;
  cin >> n;
  vector<string> s = genGrayCode(n);
  for (auto i : s)
    cout << i << "\n";
}