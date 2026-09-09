//P1789 【Mc生存】插火把
#include <bits/stdc++.h>
using namespace std;
int a[110][110]={0};int cnt=0;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    while(m--){
        int x,y;
        cin>>x>>y;
        for(int i=x-2;i<=x+2;i++){
            if(i>=1)a[i][y]=1;
        }
        for(int i=y-2;i<=y+2;i++){
            if(i>=1)a[x][i]=1;
        }
        a[x+1][y+1]=a[x-1][y-1]=a[x-1][y+1]=a[x+1][y-1]=1;
    }
    while(k--){
        int x,y;
        cin>>x>>y;
        for(int i=x-2;i<=x+2;i++){
            for(int j=y-2;j<=y+2;j++){
                if(i>=1 && j>=1)a[i][j]=1;
            }
        }
    }
    for(register int i=1;i<=n;i++){
        for(register int j=1;j<=n;j++){
            if(!a[i][j])cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
