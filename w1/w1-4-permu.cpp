#include <bits/stdc++.h>
using namespace std;

vector<string> res;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    do {
        res.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << res.size() << "\n";
    for (auto str : res)
        cout << str << "\n";

    return 0;
}
