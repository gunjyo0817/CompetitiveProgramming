#include<bits/stdc++.h>
using namespace std;

map<string, int> mp;
vector<tuple<int, int, string>> vt;

int main() {
    mp["elder"] = 8;
    mp["nursy"] = 7;
    mp["kit"] = 6;
    mp["warrior"] = 5;
    mp["appentice"] = 4;
    mp["medicent"] = 3;
    mp["deputy"] = 2;
    mp["leader"] = 1;

    int n, m;
    while(cin >> n >> m) {
        decltype(vt)().swap(vt);
        for (int i = 0 ; i < n ; i++) {
            string name, pos;
            int age;
            cin >> name >> pos >> age;
            vt.push_back({mp[pos], age, name});
        }
        sort(vt.begin(), vt.end(), [](auto &a, auto &b) {
            auto [a0, a1, a2] = a;
            auto [b0, b1, b2] = b;
            if (a0 != b0) return a0 > b0;
            if (a0 == 4 && a1 != b1) return a1 < b1;
            if (a1 != b1) return a1 > b1;
            return a2 < b2;
        });
        for (int i = 0 ; i < m && i < n; i++) cout << get<2>(vt[i]) << "\n";
    }
}

