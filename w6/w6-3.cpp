#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dir[1005][1005];
bool visited[1005][1005];
string s = "DURL";

int main() {
    int n, m;
    cin >> n >> m;
    int sx, sy, ex, ey;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                sx = i;
                sy = j;
            }
            if (grid[i][j] == 'B') {
                ex = i;
                ey = j;
            }
            if (grid[i][j] == '#') 
                visited[i][j] = true;
        }
    }
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dir[sx][sy] = -1;
    visited[sx][sy] = true;
    int step = 0;
    int nx, ny;
    while (q.size()) {
        int round = q.size();
        while(round--) {
            auto [x, y] = q.front(); q.pop();
            for (int k = 0 ; k < 4 ; k++) {
                nx = x + dx[k];
                ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (visited[nx][ny]) continue;
                visited[nx][ny] = true;
                dir[nx][ny] = k;
                if (nx == ex && ny == ey) break;
                q.push({nx, ny});
            }
            if (nx == ex && ny == ey) break;
        }
        step++;
        if (nx == ex && ny == ey) break;
    }
    if (nx == ex && ny == ey) {
        cout << "YES\n" << step << "\n";
        string ans = "";
        while (dir[nx][ny] != -1) {
            ans += s[dir[nx][ny]];
            int k = dir[nx][ny];
            nx -= dx[k];
            ny -= dy[k];
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    else cout << "NO\n";

}