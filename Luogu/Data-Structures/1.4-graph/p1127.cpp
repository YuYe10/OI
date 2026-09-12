#include <bits/stdc++.h>
using namespace std;

vector<string> g[26];
int inDeg[26], outDeg[26];
int parent[26];
bool hasEdge[26];
vector<string> res;

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) parent[a] = b;
}

void dfs(int u) {
    while (!g[u].empty()) {
        string w = g[u].back();
        g[u].pop_back();
        dfs(w.back() - 'a');
        res.push_back(w);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < 26; i++) parent[i] = i;

    for (int i = 0; i < n; i++) {
        string w;
        cin >> w;
        int u = w[0] - 'a';
        int v = w.back() - 'a';
        g[u].push_back(w);
        outDeg[u]++;
        inDeg[v]++;
        unite(u, v);
        hasEdge[u] = hasEdge[v] = true;
    }

    // 降序排序，配合 pop_back() 每次取到字典序最小的边
    for (int i = 0; i < 26; i++) {
        sort(g[i].begin(), g[i].end(), greater<string>());
    }

    // 所有出现过的字母必须在同一连通分量
    int comp = -1;
    for (int i = 0; i < 26; i++) {
        if (hasEdge[i]) {
            int root = find(i);
            if (comp == -1) comp = root;
            else if (comp != root) {
                cout << "***" << endl;
                return 0;
            }
        }
    }

    int start = -1, end = -1, cnt = 0;
    for (int i = 0; i < 26; i++) {
        int diff = outDeg[i] - inDeg[i];
        if (diff == 1) {
            start = i;
            cnt++;
        } else if (diff == -1) {
            end = i;
            cnt++;
        } else if (diff != 0) {
            cout << "***" << endl;
            return 0;
        }
    }

    if (cnt != 0 && cnt != 2) {
        cout << "***" << endl;
        return 0;
    }
    if (cnt == 2 && (start == -1 || end == -1)) {
        cout << "***" << endl;
        return 0;
    }

    if (cnt == 0) {
        // 从最小的有边的字母出发，保证字典序最小
        for (int i = 0; i < 26; i++) {
            if (hasEdge[i]) {
                start = i;
                break;
            }
        }
    }

    dfs(start);
    reverse(res.begin(), res.end());

    for (int i = 0; i < n; i++) {
        if (i) cout << '.';
        cout << res[i];
    }
    cout << endl;

    return 0;
}
