#include<bits/stdc++.h>
using namespace std;

int a, b, c, d;
int M, S, T;

int fill(int gas) {
    if (M >= gas) return 0;
    return (gas - M + d - 1) / d;
}

int main () {
    cin >> a >> b >> c >> d;
    cin >> M >> S >> T;
    
    int s = 0, t = INT_MAX;

    for (int i = 0 ; b * (i-1) < S && i + fill(c * i) <= T ; i++) {
        int bt = i + fill(c*i);
        int at = T - bt;
        
        int dis = b * i + a * at;
        s = max(s, dis);
        if (dis >= S) {
            int time = bt + (S - b*i + a - 1)/a;
            t = min(t, time);
        }
    }

    if (s >= S) cout << "Yes\n" << t << "\n";
    else cout << "No\n" << s << "\n";
}