// Let sigma(n) denote the sum of divisors of an integer n. For example, sigma(12)=1+2+3+4+6+12=28.
// Your task is to calculate the sum {i=1~n} sigma(i) modulo 10^9+7.
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;
const int inv = 500000004;

int total_sum(int start, int end) {
    int a = (end - start + 1) % mod;
    int b = (start + end) % mod;
    return (((a * b) % mod) * inv) % mod;
}

signed main() {
    int n;
    cin >> n;
    int ans = 0;
    int now = 1;
    while (now <= n) {
        int cnt = n / now; // divisor
        int last = n / cnt; // largest num who has same val
        int sum = (cnt * total_sum(now, last)) % mod;
        ans = (ans + sum) % mod;
        now = last + 1;
    }
    cout << ans % mod << "\n";
    
}