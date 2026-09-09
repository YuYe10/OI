#include <bits/stdc++.h>
#define ll long long
#define inf 0xfff
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n][5]={0};
    int b[n][5]={0};
    for(int i=0;i<n;i++){
        for(int j=1;j<=4;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=4;j++){
            cin>>b[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int s=0;
        for(int j=0;j<n;j++){
            int score=0;
            int f=1;int ff=1;
            for(int k=1;k<=4;k++){
                if(b[i][k]!=a[(i+j)%n][k] && b[i][k]){
                    score=0;f=0;ff=0;
                }
                if(b[i][k]!=a[(i+j)%n][k] && b[i][k]==0 && f){
                    score=3;f=0;ff=0;
                }
                if(b[i][k]==a[(i+j)%n][k] && b[i][k] &&f && ff){
                    score=6;
                }
            }
            s+=score;
        }
        cout<<s<<' ';
    }
    return 0;
}