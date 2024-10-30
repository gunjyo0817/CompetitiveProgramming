#include<bits/stdc++.h>
using namespace std;
#define int long long

stack<pair<int, int>> st;
int ans = 0;

signed main() {
    int n, h, cur;
    while (cin >> n) {
        decltype(st)().swap(st);
        for (int i = 0 ; i < n ; i++) {
            cin >> h;
            cur = i;
            while (st.size() && st.top().second >= h) {
                auto stick = st.top();
                st.pop();
                ans = max(ans, (i - stick.first) * stick.second);
                cur = stick.first;
            }
            st.push({cur, h});
        }
        h = 0;
        while (st.size() && st.top().second >= h) {
            auto stick = st.top();
            st.pop();
            ans = max(ans, (n - stick.first) * stick.second);
        }
        cout << ans << "\n";
        ans = 0;
    }
}