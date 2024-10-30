#include<bits/stdc++.h>
using namespace std;
#define int long long



int fast_pow(int a, int b, int mod) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1ULL * (ans * a) % mod;
        b >>= 1;
        a = 1ULL * (a * a) % mod;
    }
    return ans;
}

signed main() {
    int n;
    cin >> n;
    int a, b, c;
    int mod = 1e9 + 7;
    for (int i = 0 ; i < n ; i++) {
        cin >> a >> b >> c;
        if (!b && !c) b = 1;
        else b = fast_pow(b, c, mod-1);
        if (!a && !b) cout << "1\n";
        else cout << fast_pow(a, b, mod) << "\n";
    }
}