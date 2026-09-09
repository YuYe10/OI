//P5738 【深基7.例4】歌唱比赛
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;double maxn=0.000;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a[m]={0};
        for(int j=0;j<m;j++){
            cin>>a[j];
        }
        sort(a,a+m);
        a[0]=a[m-1]=0;
        double sum=0.000;
        for(auto j:a){
            sum+=j;
        }
        double average = sum/(m-2.000);
        if(average>=maxn)maxn=average;
    }
    printf("%.2lf",maxn);
    return 0;
}