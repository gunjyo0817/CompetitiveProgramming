#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int head = n, tail = 2*n;
    vector<int> nxt(n*3 + 1);
    vector<int> pre(n*3 + 1);

    for (int i = 1 ; i <= n ; i++) {
        nxt[head+i] = pre[tail+i] = i;
        nxt[i] = tail+i;
        pre[i] = head+i;
    }
    for (int i = 0 ; i < m ; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 0) { // a to b tail
            nxt[pre[a]] = nxt[a];
            pre[nxt[a]] = pre[a];
            nxt[a] = nxt[b];
            pre[a] = b;
            pre[nxt[b]] = a;
            nxt[b] = a;
        }
        else {
            if (nxt[head+a] == tail+a) continue;
            pre[nxt[head+a]] = pre[tail+b];
            nxt[pre[tail+a]] = tail+b; // a to b tail
            nxt[pre[tail+b]] = nxt[head+a];

            pre[tail+b] = pre[tail+a];
            nxt[head+a] = tail+a;
            pre[tail+a] = head+a;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << "#" << i << ":";
        int idx = nxt[head+i];
        while(idx != tail+i){
            cout << " " << idx;
            idx = nxt[idx];
        }
        cout << "\n";
    }
}