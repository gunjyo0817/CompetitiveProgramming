#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0 ; i < n ; i++) {
        cin >>a[i];
        mx = max(mx, a[i]);
    }

    vector<int> cnt(mx + 1, 0);

    for (int num : a) {
        for (int j = 1 ; j * j <= num ; j++) {
            if (num % j == 0) {
                cnt[j]++;
                if (j != num / j) cnt[num/j]++;
            }
        }
    }

    for (int i = mx ; i >=1 ; i--) {
        if (cnt[i] >= 2) {
            cout << i << "\n";
            break;
        }
    }
}