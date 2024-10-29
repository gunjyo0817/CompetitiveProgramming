#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a, b, c;
    vector<pair<int, int>> vt;
    for (int i = 0 ; i < n ; i++) {
        cin >> a >> b >> c;
        vt.push_back({-(a + b + c), i});
    }
    sort(vt.begin(), vt.end());
    vector<bool> ans(n, 0);
    for (int i = 0 ; i < k ; i++) {
        ans[vt[i].second] = 1;
    }
    for (int i = k ; i < n ; i++) {
        auto node = lower_bound(vt.begin(), vt.end(), make_pair(vt[i].first-300, -1));
        ans[vt[i].second] = (node - vt.begin()) < k;
    }
    for (int i = 0 ; i < n ; i++) {
        cout << (ans[i] ? "Yes\n" : "No\n");
    }
    
}