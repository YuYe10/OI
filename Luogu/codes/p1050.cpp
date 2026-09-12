// P1050 循环

#include <bits/stdc++.h>
using namespace std;

struct BN {
    vector<int> d;
    BN() { d.push_back(0); }
    BN(int x) { d.clear(); if (x == 0) d.push_back(0); while (x) { d.push_back(x % 10); x /= 10; } }
    BN(const string& s) { d.clear(); for (int i = (int)s.size() - 1; i >= 0; --i) d.push_back(s[i] - '0'); trim(); }

    void trim() { while (d.size() > 1 && d.back() == 0) d.pop_back(); }

    int cmp(const BN& o) const {
        if (d.size() != o.d.size()) return d.size() < o.d.size() ? -1 : 1;
        for (int i = (int)d.size() - 1; i >= 0; --i)
            if (d[i] != o.d[i]) return d[i] < o.d[i] ? -1 : 1;
        return 0;
    }
    bool isOne() const { return d.size() == 1 && d[0] == 1; }

    void mulSmall(int x) {
        int carry = 0;
        for (size_t i = 0; i < d.size(); ++i) {
            int cur = d[i] * x + carry;
            d[i] = cur % 10;
            carry = cur / 10;
        }
        while (carry) { d.push_back(carry % 10); carry /= 10; }
        trim();
    }
    
    int divSmall(int x) {
        int rem = 0;
        for (int i = (int)d.size() - 1; i >= 0; --i) {
            int cur = rem * 10 + d[i];
            d[i] = cur / x;
            rem = cur % x;
        }
        trim();
        return rem;
    }
    void addSmall(int x) {
        d[0] += x;
        for (size_t j = 0; j < d.size() && d[j] >= 10; ++j) {
            d[j] -= 10;
            if (j + 1 == d.size()) d.push_back(0);
            d[j + 1] += 1;
        }
        trim();
    }

    BN operator*(const BN& o) const {
        vector<int> r(d.size() + o.d.size(), 0);
        for (size_t i = 0; i < d.size(); ++i)
            for (size_t j = 0; j < o.d.size(); ++j)
                r[i + j] += d[i] * o.d[j];
        int carry = 0;
        for (size_t i = 0; i < r.size(); ++i) {
            r[i] += carry;
            carry = r[i] / 10;
            r[i] %= 10;
        }
        while (carry) { r.push_back(carry % 10); carry /= 10; }
        BN res; res.d = r; res.trim(); return res;
    }
    
    BN operator-(const BN& o) const {
        BN r = *this;
        int borrow = 0;
        for (size_t i = 0; i < r.d.size(); ++i) {
            int sub = (i < o.d.size() ? o.d[i] : 0) + borrow;
            if (r.d[i] < sub) { r.d[i] += 10 - sub; borrow = 1; }
            else { r.d[i] -= sub; borrow = 0; }
        }
        r.trim();
        return r;
    }
    
    BN operator%(const BN& m) const {
        BN rem(0);
        for (int i = (int)d.size() - 1; i >= 0; --i) {
            rem.mulSmall(10);
            rem.addSmall(d[i]);
            while (rem.cmp(m) >= 0) rem = rem - m;
        }
        return rem;
    }

    string str() const {
        string s;
        for (int i = (int)d.size() - 1; i >= 0; --i) s += char('0' + d[i]);
        return s;
    }
};

static BN mulmod(const BN& a, const BN& b, const BN& m) { return (a * b) % m; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string ns; int k;
    cin >> ns >> k;
    BN n(ns);

    
    BN a = n; int x = 0;
    while (a.d[0] % 2 == 0) { a.divSmall(2); ++x; }
    BN b = n; int y = 0;
    while (b.d[0] % 5 == 0) { b.divSmall(5); ++y; }

    
    if ((x > 0 && x < k) || (y > 0 && y < k)) { cout << -1 << '\n'; return 0; }

    int u2 = 0;
    int a5 = 0, b5 = 0;

    if (x == 0) {
        BN m2(1); for (int i = 0; i < k; ++i) m2.mulSmall(2);
        BN g = n % m2;
        vector<BN> pw2; pw2.push_back(g); // pw2[i] = g^(2^i) mod m2
        for (int i = 1; i <= k - 1; ++i) pw2.push_back(mulmod(pw2.back(), pw2.back(), m2));
        int u = k - 1;
        while (u >= 1 && pw2[u - 1].isOne()) --u;
        u2 = u;
    } else {
        u2 = 0;
    }

    if (y == 0) {
        BN m5(1); for (int i = 0; i < k; ++i) m5.mulSmall(5);
        BN g = n % m5;
        vector<BN> pw5; pw5.push_back(g); // pw5[j] = g^(5^j) mod m5
        for (int j = 1; j <= k - 1; ++j) {
            BN t = pw5.back();
            BN t2 = mulmod(t, t, m5);
            BN t4 = mulmod(t2, t2, m5);
            pw5.push_back(mulmod(t4, t, m5)); // t^5
        }
        int aa = 2, bb = k - 1;
        while (aa >= 1) { // 消去因子 2
            BN t = pw5[bb];
            for (int i = 0; i < aa - 1; ++i) t = mulmod(t, t, m5);
            if (t.isOne()) --aa; else break;
        }
        while (bb >= 1) { // 消去因子 5
            BN t = pw5[bb - 1];
            for (int i = 0; i < aa; ++i) t = mulmod(t, t, m5);
            if (t.isOne()) --bb; else break;
        }
        a5 = aa; b5 = bb;
    } else {
        a5 = 0; b5 = 0;
    }

    // lcm(L2, L5) = 2^max(u2,a5) * 5^b5
    int u = max(u2, a5);
    int bb = b5;
    BN ans(1);
    for (int i = 0; i < u; ++i) ans.mulSmall(2);
    for (int i = 0; i < bb; ++i) ans.mulSmall(5);
    cout << ans.str() << '\n';
    return 0;
}
