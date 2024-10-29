#include<bits/stdc++.h>
using namespace std;

int n, k;

template <class Ty, class FuncTy>
Ty binarySearch(Ty L, Ty R, FuncTy check, vector<int> &a, vector<int> &b, vector<int> &c) {
    while (L <= R) {
        Ty Mid = L + (R - L) / 2;
        if (check(Mid, a, b, c)) R = Mid-1;
        else L = Mid+1;
    }
    return L;
}

bool check(long long m, vector<int> &a, vector<int> &b, vector<int> &c) {
    vector<long long> d(n);
    for (int i = 0 ; i < n ; i++) {
        d[i] = a[i] + b[i] * m;
    }
    partial_sort(d.begin(), d.begin()+k, d.end(), greater<long long>());
    for (int i = 0 ; i < k ; i++) {
        if (d[i] <= c[k-i-1]) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<int> a(n), b(n), c(n);
        for (int i = 0 ; i < n ; i++) {
            cin >> a[i] >> b[i];
        }
        for (int i = 0 ; i < n ; i++) cin >> c[i];
        partial_sort(c.begin(), c.begin()+k, c.end());
        long long mx = 1e9+1;

        auto l = binarySearch(0LL, mx, check, a, b, c);
        if (check(l, a, b, c)) cout << l << "\n";
        else cout << "-1\n";
    }
}