#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n+1);
        vector<int> prefix(n+1, 0);

        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
            prefix[i] = prefix[i-1] + a[i];
        }


        vector<int> l(n+1, 0);
        vector<int> r(n+2, 0);

        for (int i = n ; i >= 0 ; i--) {
            int idx = i + 1;
            while(idx <= n && prefix[idx] >= prefix[i])
                idx = l[idx];
            l[i] = idx;

            idx = i + 1;
            while(idx <= n && prefix[idx] < prefix[i])
                idx = r[idx];
            r[i] = idx;
        }

        int start = 0, end = 0;
        int ans = 0;

        while(start < n) {
            while (end <= n && r[end] < l[start])
                end = r[end];
            ans = max(ans, end - start);
            start = end = end + 1;
        }

        cout << ans << "\n";
    }
}