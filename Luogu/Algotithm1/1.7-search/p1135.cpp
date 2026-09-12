#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> k(n + 1);
    for (int i = 1; i <= n; i++) cin >> k[i];

    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[a] = 0;
    q.push(a);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == b) break;

        int up = u + k[u];
        int down = u - k[u];

        if (up <= n && dist[up] == -1) {
            dist[up] = dist[u] + 1;
            q.push(up);
        }
        if (down >= 1 && dist[down] == -1) {
            dist[down] = dist[u] + 1;
            q.push(down);
        }
    }

    cout << dist[b] << endl;
    return 0;
}
