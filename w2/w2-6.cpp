#include<bits/stdc++.h>
using namespace std;

char tbl[10][10];
set<char> row[10];
set<char> col[10];
set<char> cell[10];
bool flag = 0;

void dfs(int idx) {
    if (flag) return;
    if (idx >= 81) {
        for (int i = 0 ; i < 9 ; i++) {
            for (int j = 0 ; j < 9 ; j++)
                cout << tbl[i][j];
        }
        cout << "\n";
        flag = 1;
        return;
    }
    int i = idx / 9;
    int j = idx % 9;
    if (tbl[i][j] != '.') {
        dfs(idx + 1);
        return;
    }
    for (int num = 1 ; num <= 9 ; num++) {
        char c = num + '0';
        if (row[i].find(c) != row[i].end()) continue;
        if (col[j].find(c) != col[j].end()) continue;
        int block = 3 * (i / 3) + j / 3;
        if (cell[block].find(c) != cell[block].end()) continue;

        tbl[i][j] = c;
        row[i].insert(c);
        col[j].insert(c);
        cell[block].insert(c);

        dfs(idx + 1);

        tbl[i][j] = '.';
        row[i].erase(c);
        col[j].erase(c);
        cell[block].erase(c);
    }
}


int main() {
    string s;
    while (getline(cin, s)) {
        if (s == "end") break;

        bool valid = true;

        for (int i = 0 ; i < 9 ; i++) {
            for (int j = 0 ; j < 9 ; j++) {
                tbl[i][j] = s[i * 9 + j];
                char c = tbl[i][j];
                if (c == '.') continue;

                int block = 3 * (i / 3) + j / 3;

                if (row[i].count(c) || col[j].count(c) || cell[block].count(c)) {
                    valid = false;
                    break;
                }

                row[i].insert(c);
                col[j].insert(c);
                cell[3 * (i / 3) + j / 3].insert(c);
            }
            if (!valid) break;
        }

        if (valid) dfs(0);
        if (!flag) cout << "No solution.\n";
        
        flag = 0;
        for (int i = 0 ; i < 10 ; i++) {
            row[i].clear();
            col[i].clear();
            cell[i].clear();
        }
    }
}