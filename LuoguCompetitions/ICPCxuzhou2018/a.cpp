#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const ll MOD = 1e9+7;
ull k1, k2;

ull xorShift128Plus() {
    ull k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

struct Edge {
    int u, v;
    ull w;
};

int f[100005];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m >> k1 >> k2;
        vector<Edge> edges(m);
        for (int i=0; i < m; i++) {
            edges[i].u = (int)(xorShift128Plus() % n) + 1;
            edges[i].v = (int)(xorShift128Plus() % n) + 1;
            edges[i].w = xorShift128Plus();
        }

        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {return a.w < b.w;});

        for(int i=1; i<=n; i++) f[i] = i;
        ll ans = 0;
        int cnt=0;
        for(auto &e : edges) {
            int ru = find(e.u);
            int rv = find(e.v);
            if(ru != rv) {
                f[ru] = rv;
                ans = (ans + e.w)%MOD;
                cnt++;
                if(cnt==n-1) break;
            }
        }

        if(cnt==n-1) cout << ans << endl;
        else cout << 0 << endl;
    }
    return 0;
}