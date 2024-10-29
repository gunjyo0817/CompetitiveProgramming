#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
int a[200005];

bool valid(int target) {
    int sum = 0;
    int count = 1;
    for (int i = 0 ; i < n ; i++) {
        // cout << a[i] << "\n";
        if (count > k) return false;
        if (a[i] > target) return false;
        if (sum + a[i] > target) {
            sum = 0;
            count++;
        } 
        sum += a[i];
        // cout << "sum = " << sum << "\n";
    }
    if (count > k) return false;
    return true;
}

signed main() {
    cin >> n >> k;
    int sum = 0;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int left = 1, right = sum;
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (valid(mid)) right = mid;
        else left = mid + 1;
    }
    cout << left << "\n";
}