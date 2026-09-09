//P1047 [NOIP2005 普及组] 校门外的树
#include <bits/stdc++.h>
using namespace std;
int main(){
    int l;
    cin>>l;
    const int L=l;
    int a[L+1];
    for(int i=0;i<=L;i++){
        a[i]=1;
    }
    int m;
    cin>>m;
    while(m--){
        int l,r;
        cin>>l>>r;
        for(int i=l;i<=r;i++){
            if(a[i]!=0)a[i]=0;
        }
    }
    int sum=0;
    for(int i=0;i<=L;i++){
        sum+=a[i];
    }
    cout<<sum;
    return 0;
}