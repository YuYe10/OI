//P1563 [NOIP2016 提高组] 玩具谜题
#include <bits/stdc++.h>
using namespace std;
struct person{
    string name;
    int t;
};
int main(){
    int n;
    int m;
    int ans=1;
    cin>>n>>m;
    person a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i].t>>a[i].name;
    }
    while(m--){
        int c;
        cin>>c;
        if(c==a[ans].t){
            int temp;
            cin>>temp;
            temp%=n;
            ans=ans-temp;
            if(ans<=0){
                ans+=n;
            }
        }else{
            int temp;
            cin>>temp;
            temp%=n;
            ans+=temp;
            if(ans>n){
                ans-=n;
            }
        }
    }
    cout<<a[ans].name;
    return 0;
}