#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[200005];
int ans = 0;
unordered_map<int, int> pre;

signed main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    pre[0] = 1;
    int sum = 0;
    for (int i = 1 ; i <= n ; i++) {
        sum += a[i];
        if (pre.find(sum - x) != pre.end()) {
            ans += pre[sum - x];
        }
        pre[sum]++;
    }
    cout << ans << "\n";
}