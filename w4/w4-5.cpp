#include<bits/stdc++.h>
using namespace std;

int n, c;
int x[200005];
int y[200005];

template <typename FuncTy>
pair<double, double> ternarySearch(double L, double R, FuncTy func, double eps = 1e-6) {
while (L + eps < R) {
    double mL = L + (R - L) / 3;
    double mR = R - (R - L) / 3;
    if (func(mL) > func(mR))
        L = mL;
    else
        R = mR;
    }
    return {L, R};
}

double find_cost(double p) {
    double cost = 0.0;
    for (int i = 0 ; i < n ; i++) {
        cost += (double)(p -x[i]) * (p - x[i]);
        cost += (double)(c - y[i]) * (c - y[i]);
    }
    return cost;
}

int main() {
    cin >> n >> c;
    for (int i = 0 ; i < n ; i++) cin >> x[i] >> y[i];
    sort(x, x + n);

    double left = x[0], right = x[n-1];
    auto [a, b] = ternarySearch(left, right, find_cost);
    
    cout << fixed << setprecision(12);
    cout << find_cost(a) << "\n";
}