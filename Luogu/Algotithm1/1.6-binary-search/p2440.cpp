#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;

using namespace std;
vector<ll> a;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    ll sum=0;
    for(int i=0; i<n; i++) {
        ll x;
        cin >> x;
        a.push_back(x);
        sum += a[i];
    }

    ll ans = 0, l=1, h=sum/k;
    while(l <= h) {
        ll mid = (h+l)/2;
        ll cnt = 0;
        for(int i=0; i<n; i++) {
            cnt += a[i]/mid;
            if(cnt >= k) break;
        }
        if(cnt >= k) {
            l = mid + 1;
            ans = mid;
        } else {
            h = mid - 1;
        }
    }

    cout << ans;
    return 0;
}