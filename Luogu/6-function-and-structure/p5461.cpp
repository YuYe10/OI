//P5461 赦免战俘
#include <bits/stdc++.h>
using namespace std;
int q[1100][1100]={0};
void digui(int dis,int l,int r);
int main(){
    int n;int d=1;
    cin>>n;
    for(int i=0;i<n;i++){
        d*=2;
    }
    for(int i=1;i<=d;i++){
        for(int j=1;j<=d;j++){
            q[i][j]=1;
        }
    }
    digui(d,1,1);
    for(int i=1;i<=d;i++){
        for(int j=1;j<d;j++){
            printf("%d ",q[i][j]);
        }
        printf("%d\n",q[i][d]);
    }
    return 0;
}
void digui(int dis,int l,int r){
    if(dis==2){
        q[l][r]=0;
        return;
    }
    for(int i=l;i<=l+dis/2-1;i++){
        for(int j=r;j<=r+dis/2-1;j++){
            q[i][j]=0;
        }
    }
    digui(dis/2,l+dis/2,r);
    digui(dis/2,l+dis/2,r+dis/2);
    digui(dis/2,l,r+dis/2);
}