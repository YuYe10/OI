#include <bits/stdc++.h>

using namespace std;

class UnionFind {
private:
    vector<int> pa;
    vector<int> size;

public:
    UnionFind(int n) : pa(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            pa[i] = i;
        }
    }

    int find(int x) {
        if (pa[x] != x) {
            pa[x] = find(pa[x]);
        }
        return pa[x];
    }

    void unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            if (size[rx] < size[ry]) {
                swap(rx, ry);
            }
            pa[ry] = rx;
            size[rx] += size[ry];
        }
    }

    int getMaxSize() const {
        int max_size = 0;
        for (int i = 0; i < pa.size(); ++i) {
            if (pa[i] == i) {
                max_size = max(max_size, size[i]);
            }
        }
        return max_size;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    UnionFind uf(n);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        if (x > 0 && x <= n && y > 0 && y <= n) {
            uf.unite(x - 1, y - 1);
        }
    }

    cout << uf.getMaxSize() << endl;

    return 0;
}