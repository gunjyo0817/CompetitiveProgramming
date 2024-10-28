#include <bits/stdc++.h>
using namespace std;

int ans = 0;
bool visited[10][10];
string s;
int n = 7;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool dead(int x, int y) {
    return ((x == 0 || visited[x-1][y]) && (x == n-1 || visited[x+1][y]) \
        && (y != 0 && !visited[x][y-1]) && (y != n-1 && !visited[x][y+1])) \
        || ((y == 0 || visited[x][y-1]) && (y == n-1 || visited[x][y+1]) \
        && (x != 0 && !visited[x-1][y]) && (x != n-1 && !visited[x+1][y]));
}

void bfs(int x, int y, int step) {
  if (x == 6 && y == 0) {
    if (step == 48) ans++;
    return;
  }
  if (step >= 48) return;

  visited[x][y] = 1;

  if (s[step] != '?') {
    int k = s[step] - '0';
    int nx = x + dx[k];
    int ny = y + dy[k];
    if (!(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || dead(nx, ny)))
      bfs(nx, ny, step + 1);
  } 
  else {
    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || dead(nx, ny)) continue;
      bfs(nx, ny, step + 1);
    }
  }
  visited[x][y] = 0;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> s;
  for (auto &c: s) {
    if (c == 'R') c = '0';
    else if (c == 'L') c = '1';
    else if (c == 'D') c = '2';
    else if (c == 'U') c = '3';
  }
  bfs(0, 0, 0);
  cout << ans << "\n";
}