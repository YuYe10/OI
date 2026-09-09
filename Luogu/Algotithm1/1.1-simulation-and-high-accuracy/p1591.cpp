//P1591 阶乘数码
#include <bits/stdc++.h>
using namespace std;
int aa[10005]={0};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a;
        cin>>n>>a;
        aa[1]=1;
        int num=1;
        for(register int i=2;i<=n;i++){
            int jw=0;
            for(register int j=1;j<=num;j++){
                aa[j]=aa[j]*i+jw;
                jw=aa[j]/10;
                aa[j]%=10;
            }
            while(jw>0){
                aa[num+1]=jw%10;
                num++;
                jw/=10;
            }
        }
        int ans=0;
        for(register int j=1;j<=num;j++){
            if(aa[j]==a)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}