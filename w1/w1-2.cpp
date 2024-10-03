#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < (1 << n); i++) {
    int num = i ^ (i >> 1);
    cout << bitset<16>(num).to_string().substr(16 - n) << "\n";
  }
}