#include<bits/stdc++.h>
#define int long long
using namespace std;

// b! = (b!)^(mod-2)
// ans = a! * (b!)^(mod-2) * ((a-b)!)^mod-2

const int mod = 1e9+7;
const int N = 1000005;
 
int pow(int a, int b){
    int res = 1;
    while(b) {
        if (b & 1) res = (res * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

signed main(void){
    int n, a, b;
    vector<int> f(N), p(N, -1);
    f[0] = f[1] = p[0] = p[1] = 1;
    for (int i = 2 ; i < N ; i++) 
        f[i] = (f[i-1] * i) % mod;

    cin >> n;
    while(n--) {
        cin >> a >> b;
        if (p[b] == -1) p[b] = pow(f[b], mod - 2);
        if (p[a-b] == -1) p[a-b] = pow(f[a-b], mod - 2);
        int ans = (f[a] * p[b]) % mod;
        ans = (ans * p[a-b]) % mod; 
        cout << ans << "\n";
    }
    return 0;
}