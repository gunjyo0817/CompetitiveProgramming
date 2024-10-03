#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
int sum = 0;
int a[25];
int mn = INT_MAX;

void dfs(int i, int cnt) {
    if (i == n) {
        mn = min(mn, abs((sum - cnt) - cnt));
        return;
    }
    // Choose
    dfs(i + 1, cnt + a[i]);
    // Not choose
    dfs(i + 1, cnt);
    return ;
}

signed main(){
    cin >> n;
    for (int i = 0 ; i < n ; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    dfs(0, 0);
    cout << mn << "\n";
}