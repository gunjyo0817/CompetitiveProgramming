#include<bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    queue<int> tmp;
    int k, x;
    while(q--) {
        cin >> k;
        if (k == 1) {
            cin >> x;
            tmp.emplace(x);
        }
        if (k == 2) {
            if (pq.size()) {
                cout << pq.top() << "\n";
                pq.pop();
            }
            else {
                cout << tmp.front() << "\n";
                tmp.pop();
            }
        }
        if (k == 3) {
            while(tmp.size()) {
                pq.emplace(tmp.front());
                tmp.pop();
            }
        }
    }
}