#include<bits/stdc++.h>
using namespace std;

int sum = 0;
vector<pair<int, int>> v;

void hanoi(int i, int from, int to, int tmp){
    if(i == 1){
        sum++;
        v.push_back({from, to});
        return;
    }
    hanoi(i-1, from, tmp, to);
    sum++;
    v.push_back({from, to});
    hanoi(i-1, tmp, to, from);

}

int main(){
    int n;
    cin >> n;
    hanoi(n, 1, 3, 2);
    cout << sum << "\n";
    for(auto i : v){
        cout << i.first << " " << i.second << "\n";
    }
}