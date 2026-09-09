#include <bits/stdc++.h>
#define ll long long
using namespace std;
unordered_map<char,int> a;
int main(){
    int t;
    scanf("%d",&t);
    a['P']=3;
    a['p']=2;
    a['G']=1;
    a['g']=0;
    a['m']=0;
    while(t--){
        string s;
        cin>>s;
        int q;
        scanf("%d",&q);
        while(q--){
            int l,r;
            scanf("%d%d",&l,&r);
            l-=1;
            r-=1;
            int ans=0;
            for(register int i=l;i<=r;i++){
                ans+=a[s[i]];
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}