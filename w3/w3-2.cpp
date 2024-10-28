#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int, int>> vt;
int a, b;
int sum = 0;

signed main() {
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> a >> b;
        vt.push_back({a, b});
    }
    sort(vt.begin(), vt.end());
    for (int i = 0 ; i < n ; i++) {
        sum -= (n - i) * vt[i].first;
        sum += vt[i].second;
    }
    cout << sum << "\n";
}