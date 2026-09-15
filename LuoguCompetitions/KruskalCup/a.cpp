#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    vector<ll> pre(n), suf(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++) pre[i] = max(pre[i-1], a[i]);
    suf[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) suf[i] = max(suf[i+1], a[i]);

    for (int k = 1; k <= n; k++) {
        cout << max(pre[k-1], suf[n-k]) << " \n"[k == n];
    }
    return 0;
}
