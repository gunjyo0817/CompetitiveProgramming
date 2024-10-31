#include<bits/stdc++.h>
using namespace std;

string ans = "123456789";
unordered_set<string> visited;

int main() {
    string s;
    int a;
    for (int i = 0 ; i < 9 ; i++) {
        cin >> a;
        s += (a + '0');
    }
    if (s == ans) {
        cout << "0\n";
        return 0;
    }
    queue<string> q;
    q.push(s);
    int steps = 0;
    while (q.size()) {
        steps++;
        int len = q.size();
        // cout << "steps " << steps << "\n";
        // cout << "len = " << len << "\n";
        while (len--) {
            s = q.front(); q.pop();
            for (int i = 0 ; i < 3 ; i++) {
                for (int j = 0 ; j < 2 ; j++) {
                    swap(s[i * 3 + j], s[i * 3 + j + 1]);
                    if (ans == s) {
                        cout << steps << "\n";
                        return 0;
                    }
                    if (!visited.count(s)) {
                        q.push(s);
                        visited.insert(s);
                    }
                    swap(s[i * 3 + j], s[i * 3 + j + 1]);
                    swap(s[i + j * 3], s[i + (j + 1) * 3]);
                    if (ans == s) {
                        cout << steps << "\n";
                        return 0;
                    }
                    if (!visited.count(s)) {
                        q.push(s);
                        visited.insert(s);
                    }
                    swap(s[i + j * 3], s[i + (j + 1) * 3]);
                }
            }
        }
        
    }
}