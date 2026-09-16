#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;

using namespace std;
ll l,n,k;
ll a[100005];

bool valid(ll x) {
    ll cnt=0;
    for(int i=2; i<=n; i++) {
        ll d = a[i] - a[i-1];
        if (d>x) {
            cnt += (d-1)/x; // means ceil(d/x)-1
            if (cnt > k) return false;
        }
    }
    return cnt<=k;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> l >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    
    ll low=1,high=l,ans=l;
    while(low <= high) {
        ll mid = (high + low) / 2;
        if(valid(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans;
    return 0;
}