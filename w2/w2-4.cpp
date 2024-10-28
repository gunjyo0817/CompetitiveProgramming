#include<bits/stdc++.h>
using namespace std;

bool a[10][10];
int ans = 0;
bool col[10], diff[20], add[10];

void dfs(int i) {
    if (i == 8) {
        ans++;
        return ;
    }
    for (int j = 0 ; j < 8 ; j++) {
        if (a[i][j] || col[j] || add[i + j] || diff[j - i + 8]) continue;
        col[j] = 1;
        add[i + j] = 1;
        diff[j - i + 8] = 1;
        dfs(i + 1);
        col[j] = 0;
        add[i + j] = 0;
        diff[j - i + 8] = 0;
    }
}

int main() {
    string s;
    for (int i = 0 ; i < 8 ; i++) {
        cin >> s;
        for (int j = 0 ; j < 8 ; j++) {
            if (s[j] == '*') a[i][j] = 1;
        }
    }
    dfs(0);
    cout << ans << "\n";
}