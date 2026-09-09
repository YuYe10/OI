//P1540 [NOIP2010 提高组] 机器翻译
#include <bits/stdc++.h>
using namespace std;
queue <int> q;
int main(){
    int m,n;int cnt=0;
    cin>>m>>n;
    
    int aq[1005]={0};
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(aq[x]){
            continue;
        }else{
            
            if(q.size()==m){
                aq[q.front()]=0;
                q.pop();
            }
        }
        q.push(x);
        aq[x]=1;
        cnt++;
        
    }
    cout<<cnt;
    return 0;
}