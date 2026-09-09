#include <bits/stdc++.h>
#define ll long long
#define inf 0xfff
using namespace std;
int main(){
    ll k,a,q;
    cin>>k>>a>>q;ll cnt=a;
    for(ll i=0;i<k-1;i++){
        a=((a%722733748)*(q%722733748))%722733748;
        cnt=((cnt%722733748)*(a%722733748))%722733748;
    }
    cout<<cnt;
    return 0;
}