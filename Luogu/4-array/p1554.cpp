//P1554 梦中的统计
#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int a[10]={0};
    for(int i=m;i<=n;i++){
        int t=i;
        while(t!=0){
            int x=t%10;
            t/=10;
            a[x]++;
        }
    }
    for(int i=0;i<10;i++)cout<<a[i]<<" ";
    return 0;
}