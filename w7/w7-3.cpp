#include<bits/stdc++.h>
#define int long long
using namespace std;
#define N 1000005


vector<int> cnt(N);

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        mx = max(mx, a[i]);
    }

    vector<int> primes;
    vector<int> LPFs(mx + 1, 1);
    vector<int> mobius(mx + 1); 
    // 0: 奇數個質因數的平方數相乘
    // 1: 偶數個不重複的質因數相乘
    // -1: 奇數個不重複的質因數相乘
    mobius[1] = 1;
    for (int i = 2; i <= mx; ++i) {
        if (LPFs[i] == 1) {
            LPFs[i] = i;
            primes.emplace_back(i);
            mobius[i] = -1; // only itself
        }

        for (auto p : primes) {
            if (1LL * i * p > mx) break;
            LPFs[i * p] = p;
            mobius[i * p] = (LPFs[i] == p) ? 0 :
                            0 - mobius[i];
            // (LPFs[i] == p) -> i 包含 p 的平方 -> 0
            // else -> 奇變偶 偶變奇
            if (i % p == 0) break;
        }
    }
    
 
    int ans = 0;
    for (int i = 1 ; i <= mx ; i++) {
        int res = 0;
        for (int j = i ; j <= mx ; j += i) {
            res += cnt[j];
        }
        ans += res * (res - 1) / 2 * mobius[i];
    }
    cout << ans << "\n";
}