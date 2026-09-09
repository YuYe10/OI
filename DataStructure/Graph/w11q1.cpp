#include <bits/stdc++.h>  

using namespace std;  

const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  

bool check(int x, int y, int n, int m) {  
    return x >= 0 && x < n && y >= 0 && y < m;  
}  

int main() {  
    int n, m;  
    cin >> n >> m;  

    vector<string> g(n);  
    pair<int, int> start, boss;  

    for (int i = 0; i < n; ++i) {  
        cin >> g[i];  
        for (int j = 0; j < m; ++j) {  
            if (g[i][j] == 'r') {  
                start = {i, j};  
            } else if (g[i][j] == 'a') {  
                boss = {i, j};  
            }  
        }  
    }  

    queue<pair<int, int>> q;  
    vector<vector<int>> t(n, vector<int>(m, -1));  
    q.push(start);  
    t[start.first][start.second] = 0;  

    while (!q.empty()) {  
        int x = q.front().first;  
        int y = q.front().second;  
        q.pop();  

        for (const auto& dir : directions) {  
            int nx = x + dir[0];  
            int ny = y + dir[1];  

            if (check(nx, ny, n, m)) {  
                if (g[nx][ny] == '#') {  
                    continue;  
                }  

                int nt = t[x][y] + 1;  
                if (g[nx][ny] == 'x') {  
                    nt += 1;  
                }  

                if (t[nx][ny] == -1 || nt < t[nx][ny]) {  
                    t[nx][ny] = nt;  
                    q.push({nx, ny});  
                }  
            }  
        }  
    }  

    int result = t[boss.first][boss.second];  
    cout << (result != -1 ? result : -1) << endl;  

    return 0;  
}
/* 
7 8
#.#####.
#.a#..r.
#..#x...
..#..#.#
#...##..
.#......
........

13
*/