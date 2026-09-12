#include <bits/stdc++.h>
using namespace std;

const int MOD = 10000;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    // f[i] = 2*f[i-1] + f[i-3]
    if (n == 1) { cout << 1 << '\n'; return 0; }
    if (n == 2) { cout << 2 << '\n'; return 0; }

    int a = 1, b = 1, c = 2;
    for (int i = 3; i <= n; i++) {
        int d = (2 * c + a) % MOD;
        a = b; b = c; c = d;
    }
    cout << c << '\n';
    return 0;
}