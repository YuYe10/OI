#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, k;
int main() {

    scanf("%d%d",&n,&k);
    vector<vector<int>> g(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> d(n+1, -1);
    vector<int> p(n+1, 0);
    vector<int> pn(n+1, 0);
    queue<int> q;
    d[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                p[v] = u;
                q.push(v);
            }
        }
    }

    int max_d = 0;
    for (int i = 1; i <= n; i++) {
        max_d = max(max_d, d[i]);
    }

    for (int u = 1; u <= n; u++) {
        for (int v : g[u]) {
            if (v != p[u]) {
                pn[u]++;
            }
        }
    }

    ll del_cnt = 0;
    for (int u = 1; u <= n; u++) {
        if (d[u] < max_d) {
            del_cnt += (k - pn[u]);
        }
    }

    printf("%d %d\n",max_d,del_cnt);

    return 0;
}