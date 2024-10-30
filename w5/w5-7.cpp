#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[2000005];
deque<pair<int, int>> dq;

signed main() {
    // keep decrease deque
    int n, k;
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        while (dq.size() && dq.front().first <= i - k) dq.pop_front();
        while (dq.size() && dq.back().second < a[i]) dq.pop_back();
        dq.push_back({i, a[i]});
        if (i >= k) cout << dq.front().second << " ";
    }
    for (int i = n + 1 ; i < n + k; i++) {
        while (dq.size() && dq.front().first <= i - k) dq.pop_front();
        while (dq.size() && dq.back().second < a[i - n]) dq.pop_back();
        dq.push_back({i, a[i - n]});
        cout << dq.front().second << " \n"[i == n + k - 1];
    }
}