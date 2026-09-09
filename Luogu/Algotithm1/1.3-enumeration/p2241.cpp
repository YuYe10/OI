//P2241 统计方形（数据加强版）
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long m,n;
    cin>>n>>m;
    long long num_square=0;
    long long num_rectangle=((n*(n+1))/2)*((m*(m+1))/2);//对于一个m*n的棋盘，共有矩形 (m+m-1+m-2+…+1)*(n+n-1+n-2+…+1)即[m*(m+1)/2]*[n(n+1)/2]个
    for(long long i=1;i<=min(m,n);i++){
        num_square+=(n-i+1)*(m-i+1);
    }
    cout<<num_square<<' '<<num_rectangle-num_square;
    return 0;
}