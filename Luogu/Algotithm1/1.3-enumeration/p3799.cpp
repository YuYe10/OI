// P3799 小 Y 拼木棒
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

unordered_map<ll, int> m;

ll Catalan(ll k, ll n){
    return (k == 1 ? n : n*(n-1)/2) % MOD;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    int n;
    cin >> n;
    int t=n;
    ll maxx=0;
    while(n--){
        ll x;
        cin >> x;
        maxx = max(maxx, x);
        m[x]++;
    }
    ll ans = 0;
    for(int i=2; i <= maxx; i++){
        if(m[i] >= 2){
            ll c = Catalan(2, m[i]) % MOD;
            for(int j=1; j <= i/2; j++){
                if(j != i-j && m[j] >= 1 && m[i-j] >= 1)
                    ans += c * Catalan(1, m[j]) * Catalan(1, m[i-j]) % MOD;
                if(j == i-j && m[j] >= 2)
                    ans += c * Catalan(2, m[j]) % MOD;
                ans %= MOD;
            }
        }
    }
    cout << ans;
    return 0;
}