#include<bits/stdc++.h>
using namespace std;
#define int long long

int a;
vector<tuple<int, int, int, int>> info;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> vt[2005];
        decltype(info)().swap(info);
        for (int i = 0 ; i < n ; i++) {
            int mx = INT_MIN;
            int sum = 0;
            int k;
            cin >> k;
            for (int j = 0 ; j < k ; j++) {
                cin >> a;
                sum += a;
                vt[i].push_back(a);
                mx = max(mx, a);
            }
            info.push_back({sum, mx, k, i});
        }
        sort(info.begin(), info.end(), [](auto &a, auto &b) {
            auto [a0, a1, a2, a3] = a;
            auto [b0, b1, b2, b3] = b;
            if (a0 != b0) return a0 > b0;
            if (a1 != b1) return a1 > b1;
            if (a2 != b2) return a2 > b2;
            return a3 < b3;
        });
        for (int i = 0 ; i < n ; i++) {
            auto [_0, _1, _2, idx] = info[i];
            int len = vt[idx].size();
            for (int j = 0 ; j < len ; j++) {
                cout << vt[idx][j] << " \n"[j == len - 1];
            }
        }
    }

}