#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;

using namespace std;
ll l,n,m;
ll a[50005];

bool valid(ll x) {
    ll cnt=0, last=0;
    for(int i=1; i<=n+1; i++) {
        if(a[i]-a[last] < x) {
            cnt++;
        }else{
            last=i;
        }
    }
    return cnt<=m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> l >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    a[n+1] = l;
    ll low=1,high=l,ans=0;
    while(low <= high) {
        ll mid = (high + low) / 2;
        if(valid(mid)) {
            ans = mid;
            low = mid+1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans;
    return 0;
}