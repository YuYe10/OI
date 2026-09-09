#include <bits/stdc++.h>
using namespace std;
int main(){
    int time;
    cin>>time;
    for(int i=0;i<time;i++){
        int n;int flag1=1;int flag2=1;
        cin>>n;
        string s;int l=0,r=0;int ans=0;
        cin>>s;
        if(s=="W"){cout<<0<<endl;continue;}
        if(s=="WB" || s=="BW"){cout<<1<<endl;continue;}
        if(s=="WW"){cout<<0<<endl;continue;}
        for(int i=0;i<=n/2;i++){
            if(s[i]=='B' && flag1){l=i;flag1=0;}
            if(s[n-i-1]=='B' && flag2){r=n-i-1;flag2=0;}
        }
        ans=r-l+1;
        cout<<ans<<endl;
    }
    return 0;
}