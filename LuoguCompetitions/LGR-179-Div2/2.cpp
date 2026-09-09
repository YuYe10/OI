#include <bits/stdc++.h>
#define ll long long
#define inf 0xfff
using namespace std;
int main(){
    register ll t;
    scanf("%d",&t);
    while(t--){
        register ll x,a,b;
        scanf("%ld%ld%ld",&x,&a,&b);
        register ll now=x;
        register ll next=a*x-b;
        while(now>next && now>=0){
            now=next;
            next=a*next-b;
        }
        cout<<now<<endl;
    }
    return 0;
}