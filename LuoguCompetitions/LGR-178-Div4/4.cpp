#include <bits/stdc++.h>
#define ll long long
#define inf 0xfff
using namespace std;
int main(){
    ll n,q;
    ll v;
    cin>>n>>q>>v;
    ll a[n+1]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        a[x]=y;
    }
    sort(a+1,a+n+1);
    ll ans=n;
    while(a[n-ans+1]<v){
        ans--;
    }
    cout<<ans;
    return 0;
}