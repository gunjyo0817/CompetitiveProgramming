#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int tar;
vector<int> a(10);
int tbl[5] = {0, 50, 50*50, 50*50*50, 50*50*50*50};
unordered_set<int> s;
queue<vector<int>> Q;
int enc;

bool check(vector<int> &vt) {
    for (auto i : vt) {
        if (i == tar) return true;
    }
    return false;
}

int encode(vector<int> &vt) {
    int sum = 0;
    for (int i = 0 ; i < n ; i++) {
        sum += (tbl[i]+1) * vt[i];
    }
    return sum;
}

void update(vector<int> &vt) {
    enc = encode(vt);
    if (!s.count(enc)) {
        Q.emplace(vt);
        s.insert(enc);
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    cin >> tar;

    bool valid = 0;
    for (int i = 0 ; i < n ; i++) {
        if (a[i] == tar) {
            cout << "1\n";
            return 0;
        }
        if (a[i] > tar) {
            valid = 1;
        }
    }
    if (!valid || n == 1) {
        cout << "-1\n";
        return 0;
    }
    
    vector<int> v(n, 0);
    vector<int> tmp;
    Q.emplace(v);
    int step = 0;

    while(Q.size()) {
        int round = Q.size();
        while(round--) {
            v = Q.front(); Q.pop();
            
            if (check(v)) {
                cout << step << "\n";
                return 0;
            }

            for (int i = 0 ; i < n ; i++) {
                // clear
                tmp = v;
                tmp[i] = 0;
                update(tmp);
                
                // fill up
                tmp = v;
                tmp[i] = a[i];
                update(tmp);
                
                // i to j
                for (int j = 0 ; j < n ; j++) {
                    if (i == j) continue;
                    tmp = v;
                    int fill = min(v[i], a[j] - v[j]);
                    tmp[i] -= fill;
                    tmp[j] += fill;
                    update(tmp);
                }
            }
        }
        step++;
    }
    cout << "-1\n";
}