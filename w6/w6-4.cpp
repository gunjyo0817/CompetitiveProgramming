#include<bits/stdc++.h>
using namespace std;

bool visited[1005][1005];
char grid[1005][1005];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;

void dfs(int x, int y) {
    if (visited[x][y]) return;
    visited[x][y] = 1;
    for (int k = 0 ; k < 4 ; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        dfs(nx, ny);
    }
}

int main() {
    cin >> n >> m;
    queue<pair<int, int>> q;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '.') {
                q.push({i, j});
            }
            else visited[i][j] = 1;
        }
    }
    int ans = 0;
    while(q.size()) {
        auto [x, y] = q.front(); q.pop();
        if (visited[x][y]) continue;
        ans++;
        dfs(x, y);
    }
    cout << ans << "\n";
}