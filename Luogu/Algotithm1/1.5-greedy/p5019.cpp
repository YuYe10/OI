#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    long long ans = 0, prev = 0, cur;
    for (int i = 0; i < n; i++) {
        cin >> cur;
        if (cur > prev) ans += cur - prev;
        prev = cur;
    }
    cout << ans << "\n";
    return 0;
}
