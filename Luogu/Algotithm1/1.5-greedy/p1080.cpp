#include <bits/stdc++.h>
using namespace std;

const long long BASE = 1000000000;

// 大整数，小端存储，每位 BASE 进制。只需支持乘小整数、除以小整数、比较、输出
struct Big {
    vector<long long> d;

    Big(long long x = 0) {
        while (x) {
            d.push_back(x % BASE);
            x /= BASE;
        }
    }

    void mul(int x) {
        long long carry = 0;
        for (size_t i = 0; i < d.size(); i++) {
            carry += d[i] * x;
            d[i] = carry % BASE;
            carry /= BASE;
        }
        while (carry) {
            d.push_back(carry % BASE);
            carry /= BASE;
        }
    }

    Big div(int x) const {
        Big r;
        r.d.assign(d.size(), 0);
        long long rem = 0;
        for (int i = (int)d.size() - 1; i >= 0; i--) {
            rem = rem * BASE + d[i];
            r.d[i] = rem / x;
            rem %= x;
        }
        while (!r.d.empty() && r.d.back() == 0) r.d.pop_back();
        return r;
    }

    bool operator<(const Big &o) const {
        if (d.size() != o.d.size()) return d.size() < o.d.size();
        for (int i = (int)d.size() - 1; i >= 0; i--)
            if (d[i] != o.d[i]) return d[i] < o.d[i];
        return false;
    }

    string str() const {
        if (d.empty()) return "0";
        string s = to_string(d.back());
        for (int i = (int)d.size() - 2; i >= 0; i--) {
            string t = to_string(d[i]);
            s += string(9 - t.size(), '0') + t;
        }
        return s;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    int a0, b0;
    cin >> a0 >> b0;

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;

    // 相邻交换：i 在 j 前更优 <=> max(bj, ai*bi) <= max(bi, aj*bj)，即按 ai*bi 升序
    sort(p.begin(), p.end(), [](const pair<int, int> &x, const pair<int, int> &y) {
        return (long long)x.first * x.second < (long long)y.first * y.second;
    });

    Big prod(a0), ans;
    for (int i = 0; i < n; i++) {
        Big cur = prod.div(p[i].second);
        if (ans < cur) ans = cur;
        prod.mul(p[i].first);
    }

    cout << ans.str() << "\n";
    return 0;
}
