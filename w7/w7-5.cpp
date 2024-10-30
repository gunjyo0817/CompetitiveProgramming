#include<bits/stdc++.h>
#define int long long
using namespace std;

pair<int, int> extgcd(int a, int b) {
    if (b == 0) return {1, 0};
    auto [xp, yp] = extgcd(b, a % b);
    return {yp, xp - a / b * yp};
}

int mod_reverse(int a, int n) { //ax=1(mod n) 求 a 的逆元 x
	auto [x, y] = extgcd(a, n);
    return (x % n + n) % n;
}

typedef struct CH_Remainder{
	int mod_num, result;
}CH_Remainder,ch_remainder[100];

int Ch_remainder_theorem(ch_remainder a) {
	int k = a[0].mod_num;
	int b = 0, z = 0;
	for (int i = 1; a[i].mod_num; i++)
		k *= a[i].mod_num;
	for (int i = 0; a[i].mod_num; i++) {
		z = mod_reverse(k / a[i].mod_num, a[i].mod_num);//乘法逆元
		if (z == -1) return -1;
		b += (a[i].result * (k / a[i].mod_num) * z);
	}
	return b % k;
}

signed main() {
    int n;
    cin >> n;
    while(n--) {
        int k1, k2, k3, r1, r2, r3;
        cin >> k1 >> r1 >> k2 >> r2 >> k3 >> r3;
        ch_remainder crt = {{k1, r1}, {k2, r2}, {k3, r3}};
	    cout << Ch_remainder_theorem(crt) << "\n";
    }
}