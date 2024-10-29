#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int, int>> vt;

signed main (){
    int n, x;
    cin >> n >> x;
    for (int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        vt.push_back({a, i+1});
    }
    bool ans = false;
    sort(vt.begin(), vt.end());
    for (int i = 0 ; i < n - 2 && !ans; i++) {
        int target = x - vt[i].first;
        int l = i + 1, r = n - 1;

        while(l < r) {
            int a = vt[l].first;
            int b = vt[r].first;
            if (a + b == target) {
                ans = 1;
                cout << vt[i].second << " " << vt[l].second << " " << vt[r].second << "\n";
                break;
            }
            else if (a + b < target) l++;
            else r--;
        }
    }
    if (!ans) cout << "IMPOSSIBLE\n";
}