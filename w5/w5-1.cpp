#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    for (int i = 0; i < n; i++) {
        cin >> a;
        left.push(a);

        if (!right.empty() && left.top() > right.top()) {
            right.push(left.top());
            left.pop();
            left.push(right.top());
            right.pop();
        }
        
        if (left.size() >= right.size() + 2) {
            right.push(left.top());
            left.pop();
        } 
        else if (right.size() >= left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
        cout << left.top() << " \n"[i == n-1];
    }
}