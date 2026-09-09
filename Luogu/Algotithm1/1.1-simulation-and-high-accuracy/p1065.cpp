//P1065 [NOIP2006 提高组] 作业调度方案
#include <bits/stdc++.h>
using namespace std;
struct gears{
    int num;//在第 num 台机器上加工
    int time_cost;
};
int main(){
    
    int m,n;
    cin>>m>>n;
    int order[(m+1)*(n+1)]={0};
    bool mac[m+1][10005]={0};//mac[机器编号][时间]
    gears g[n+1][m+1]={0};//a[第几个工件][第几步]
    int step[n+1]={0};//每个工件加工到了第几步
    int last_time[n+1]={0};//每个工件上次是 last_time[工件编号] 时加工完的
    int ans=0;
    for(int i=1;i<=m*n;i++){
        cin>>order[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j].num;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j].time_cost;
        }
    }
    for(int i=1;i<=m*n;i++){
        int now_order=order[i];
        step[now_order]++;
        int st=step[now_order];//以st计此时该工件的步数
        int num = g[now_order][st].num;
        int time_cost =g[now_order][st].time_cost;
        int now_time=0;
        for(int j=last_time[now_order]+1;;j++){
            if(mac[num][j]){
                now_time=0;
            }
            else{
                now_time++;
                //mac[num][j] = 1;//??//
            }
            if(now_time==time_cost){
                for (int k = j - time_cost + 1; k <= j; k++) {
                    mac[num][k] = 1;
                }
                if(j>ans)ans=j;
                last_time[now_order]=j;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}