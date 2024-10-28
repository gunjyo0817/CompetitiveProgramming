#include <bits/stdc++.h>
using namespace std;

int t, m, n;
int len;
int ans = 0;

int mask;
int lowbit(int x) {
  return x & -x;
}

void dfs(int M, int QL, int QR, int RL, int RR) {
  if (M == mask) {
    ++ans;
    return;
  }
  // Queen
  if (m > 0) {
    int legal = mask & ~(M | QL | QR | RL | RR);
    for (int num = 0 ; legal ; legal ^= num) {
      num = lowbit(legal);
      m--;
      dfs(M | num, (QL | num) << 1, (QR | num) >> 1, RL << 1, RR >> 1);
      m++;
    }
  }
  // Rock
  if (n > 0) {
    int legal = mask & ~(M | QL | QR);
    for (int num = 0 ; legal ; legal ^= num) {
      num = lowbit(legal);
      n--;
      dfs(M | num, QL << 1, QR >> 1, (RL | num) << 1, (RR | num) >> 1);
      n++;
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> m >> n;
    if (m == 0) {
        ans = 1;
        for (int i = 2 ; i <= n ; i++) ans *= i;
    }
    else {
        len = m + n;
        mask = (1 << len) - 1;
        dfs(0, 0, 0, 0, 0);
    }
    cout << ans << "\n";
    ans = 0;
  }
}