#include<bits/stdc++.h>
using namespace std;

string s;
deque<char> dq, tmp;

int main() {
    while (cin >> s) {
        int n = s.length();
        bool front = 0;
        for (int i = 0 ; i < n ; i++) {
            if (s[i] == '[') {
                while (tmp.size()) {
                    dq.push_front(tmp.back());
                    tmp.pop_back();
                }
                front = 1;
            }
            else if (s[i] == ']') {
                while (tmp.size()) {
                    dq.push_front(tmp.back());
                    tmp.pop_back();
                }
                front = 0;
            }
            else {
                if (front) tmp.push_back(s[i]);
                else dq.push_back(s[i]);
            }
        }
        while (tmp.size()) {
            dq.push_front(tmp.back());
            tmp.pop_back();
        }
        while (dq.size()) {
            cout << dq.front();
            dq.pop_front();
        }
        cout << "\n";
    }
}