#include<bits/stdc++.h>
using namespace std;

stack<pair<int, int>> st;

int main() {
    // increase stack
    int n, x;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> x;
        while (st.size() && st.top().second >= x) st.pop();
        if (st.empty()) cout << 0 << " \n"[i == n];
        else cout << st.top().first << " \n"[i == n];
        st.push({i, x});
    }
}