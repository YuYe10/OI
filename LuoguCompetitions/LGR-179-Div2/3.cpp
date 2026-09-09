#include <bits/stdc++.h>
#define ll long long
#define inf 0xfff
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll y;
        scanf("%d",&y);
        ll x=1;
        ll ans;
        ll ans1=-1;
        ll cnt=0;
        for(;x<y;x++){
            ans=x;
            ll i=x;
            i/=10;
            while(i>0){
                ans+=i;
                i/=10;
            }
            if(ans==y){
                ans1=x;
                cnt++;
            }
        }
        if(cnt==1){
            cout<<ans1<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}