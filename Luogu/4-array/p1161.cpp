//P1161 开灯
#include <bits/stdc++.h>
using namespace std;
int a[2000005]={0};
int main(){
    
    int n;int maxx=0;
    cin>>n;
    while(n--){
        int t,a1;double a0;
        cin>>a0>>t;
        for(int i=1;i<=t;i++){
            a1=a0*i;
            if(a[a1])a[a1]=0;
            else a[a1]=1;
        }
        maxx=max(maxx,a1);
    }
    for(int i=1;i<=maxx;i++){
        if(a[i])cout<<i<<endl;
    }
    return 0;
}