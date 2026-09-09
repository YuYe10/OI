#include <bits/stdc++.h>
#define ll long long
#define inf 0xfff
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int a[n+1][m+1]={0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int ans=0;
    int i=1;
    while(n--){
        
        int max=-1e+9;
        int cost=k;
        for(int j=1;j<=m;j++){ 
            int earn=a[i][j];  
            if(earn-cost>max){
                max=earn-cost;
                cost+=k;
            }else{
                cost+=k;
            }
        }
        i++;
        ans+=max;
    }
    cout<<ans;
    return 0;
}