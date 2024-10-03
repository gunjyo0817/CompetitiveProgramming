#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[25];
int ans[25];

void print() {
    for (int i = 0 ; i < m ; ++i) {
        cout << ans[i] << " \n"[i == m - 1];
    }
}

void dfs(int i, int cnt) {
    if (cnt == m) {
        print();
        return;
    }
    if (i == n) return;
    ans[cnt++] = a[i];
    dfs(i + 1, cnt);
    --cnt;
    dfs(i + 1, cnt);
}

int main() {
    cin >> n >> m;
    for (int i = 0 ; i < n ; ++i) {
        cin >> a[i];
    }
    dfs(0, 0);
}