//P1518 [USACO2.4] 两只塔姆沃斯牛 The Tamworth Two
#include <bits/stdc++.h>
#define ll long long
#define inf 0xfff
#define endl "\n"
using namespace std;
int m[12][12];
int xf,yf,xc,yc,df,dc;
int ti=0;
bool r[15][15][15][15][5][5]={0};
void move(int x,int y,int d,int t){
    if(d==1){
        if(m[y-1][x]) (t==0) ? dc=2 : df=2;
        else (t==0) ? yc-- : yf--;
    }else if(d==4){
        if(m[y][x-1]) (t==0) ? dc=1 : df=1;
        else (t==0) ? xc-- : xf--;
    }else if(d==3){
        if(m[y+1][x]) (t==0) ? dc=4 : df=4;
        else (t==0) ? yc++ : yf++;
    }else{
        if(m[y][x+1]) (t==0) ? dc=3 : df=3;
        else (t==0) ? xc++ : xf++;
    }
}
bool judge(){
    if(xc==xf && yc==yf)return false;
    else return true;
}
int main(){
    
    char c;
    
    for(int i=0;i<=11;i++) m[i][0]=inf,m[i][11]=inf;
    for(int i=1;i<=11;i++) m[0][i]=inf,m[11][i]=inf;
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            cin>>c;
            if(c=='.')m[i][j]=0;
            if(c=='*')m[i][j]=1;
            if(c=='F'){m[i][j]=0;xf=j;yf=i;}
            if(c=='C'){m[i][j]=0;xc=j;yc=i;}
        }
    }
    df=dc=1;
    while(judge()){
        if(r[xc][yc][xf][yf][dc][df]){
            cout<<0;
            return 0;
        }
        r[xc][yc][xf][yf][dc][df]=1;
        move(xf,yf,df,1);
        move(xc,yc,dc,0);
        ti++;
    }
    cout<<ti;
    return 0;
}