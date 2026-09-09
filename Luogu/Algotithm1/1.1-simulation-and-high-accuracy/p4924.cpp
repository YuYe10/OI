//P4924 [1007] 魔法少女小Scarlet
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    int t=1;
    cin>>n>>m;
    int a[n+1][n+1]={0},b[n+1][n+1]={0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=t;
            t++;
        }
    }
    while(m--){
        int x,y,r,z;
        cin>>x>>y>>r>>z;
        if(!z){
            for(int i=x-r;i<=x+r;i++){
                for(int j=y-r;j<=y+r;j++){
                    b[x-y+j][x+y-i]=a[i][j];
                }
            }
            for(int i=x-r;i<=x+r;i++){
                for(int j=y-r;j<=y+r;j++){
                    a[i][j]=b[i][j];
                }
            }
        }else{
            for(int i=x-r;i<=x+r;i++){
                for(int j=y-r;j<=y+r;j++){
                    b[x+y-j][y-x+i]=a[i][j];
                }
            }
            for(int i=x-r;i<=x+r;i++){
                for(int j=y-r;j<=y+r;j++){
                    a[i][j]=b[i][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}