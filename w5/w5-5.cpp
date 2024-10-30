#include<bits/stdc++.h>
using namespace std;


stack<char> st;

int main() {
    string s;
    cin >> s;
    for (auto c : s) {
        if (c == 'S') st.emplace(c);
        else {
            if (st.size() && st.top() == 'S') st.pop();
            else st.emplace(c);
        }
    }
    cout << st.size() << "\n";
}