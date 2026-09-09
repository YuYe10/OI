#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
map<ull, bool> a;
map<ull, ull> b;
ull n, m;

inline int depth(ull u) {
    if (u == 0) return 0;
    int ans = 0;
    while(u){
        ans++;
        u >>= 1;
    }
    return ans;
}


ull full_size(ull u) {
    int d = depth(u);
    if (d > n) 
        return 0;
    int h = n - d + 1;
    if (h < 0) return 0;
    return (1ULL << h) - 1;
}

ull get_size(ull u) {
    if (b.count(u))
        return b[u];
    else
        return full_size(u);
}

ull find_root(ull u) {
    while (u != 1) {
        if (a.count(u))
            break;
        u /= 2;
    }
    return u;
}

int main() {
    cin >> n >> m;
    ull xor_sum = 0;
    for (int i = 0; i < m; i++) {
        ull op, u;
        cin >> op >> u;
        if (op == 1) {
            if (u == 1 || a.count(u)) 
                continue;
            a[u] = true;
            ull d = get_size(u);
            ull p = u / 2;
            while (p != 0) {
                ull old = get_size(p);
                b[p] = old - d;
                if (a.count(p))
                    break;
                p = p / 2;
            }
        } else if (op == 2) {
            ull r = find_root(u);
            ull ans = get_size(r);
            xor_sum ^= ans;
        }
    }
    cout << xor_sum << endl;
    return 0;
}