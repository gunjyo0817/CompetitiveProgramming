#include<bits/stdc++.h>
#define int long long
using namespace std;

pair<int, int> extgcd(int a, int b) {
    if (b == 0) return {1, 0};
    auto [xp, yp] = extgcd(b, a % b);
    return {yp, xp - a / b * yp};
}

int n, m, x, y, vx, vy;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> x >> y >> vx >> vy;
        // (nx, ny) = (x + t * vx, y + t * vy)
        // nx == k1 * n or ny == k2 * m

        if (!vx) {
            if (x == 0 || x == n) 
                cout << x << " " << (vy == 1 ? m : 0) << "\n";
            else cout << "-1\n";
            continue;
        }
        if (!vy) {
            if (y == 0 || y == m)
                cout << (vx == 1 ? n : 0) << " " << y << "\n";
            else cout << "-1\n";
            continue;
        }

        if (vx == -1) x = n - x;
        if (vy == -1) y = m - y;
        int c = x - y;
        int g = gcd(n, m);

        // 沒有整數解
        if (c % g) {
            cout << "-1\n";
            continue;
        }

        auto [a, b] = extgcd(n, m);
        int scale = c / g;
        a *= scale;
        b *= scale;

        // 最小非負解
        int N = m / g;
        a = (a % N + N - 1) % N + 1;
        b = - (c - a * n) / m;
        
        int fx = (a % 2) ? n : 0;
        int fy = (b % 2) ? m : 0;

        if (vx == -1) fx = n - fx;
        if (vy == -1) fy = m - fy;

        cout << fx << " " << fy << "\n";
    }
}