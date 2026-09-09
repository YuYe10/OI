//P1706 全排列问题
#include <bits/stdc++.h>
using namespace std;
int n,judge[105]={0},used[105];
void myprint(){
    for(int i=1;i<=n;i++)
        cout<<setw(5)<<used[i];
    cout<<endl;
}
void dfs(int k){
    if(k==n+1){
        myprint();
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!judge[i]){
            judge[i]=1;
            used[k]=i;
            dfs(k+1);
            judge[i]=0;
        }
    }

}
int main(){
    cin>>n;
    dfs(1);
    return 0;
}