// P2036 [COCI 2008/2009 #2] PERKET
#include <bits/stdc++.h>
using namespace std;
int n, ans=1000000001;
int s[15], b[15];
void dfs(int u, int x, int y){
    if(u>n){
        if(x==1&&y==0)return;
        ans = min(abs(x-y), ans);
        return;
    }
    
   
    dfs(u+1, x, y);
    dfs(u+1, x*s[u-1], y+b[u-1]);

}
int main(){
    scanf("%d", &n);

    for(int i=0;i<n;++i)
        scanf("%d%d", s+i, b+i);
   
    dfs(1,1,0);

    printf("%d\n", ans);
    return 0;
}