// P2392 kkksc03考前临时抱佛脚
#include <bits/stdc++.h>
using namespace std;
int s[5];
int a[5][25];
int dp[25][1210];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    for(int i=1;i<=4;++i)
        cin >> s[i];

    for(int i=1;i<=4;++i)
        for(int j=1; j<=s[i]; j++)
            cin >> a[i][j];

    int v, ans=0;        
    for(int i=1;i<=4;++i){
        v = 0;
        for(int j=1;j<=s[i];j++){
            v += a[i][j];
        }
        
        for(int j=1;j<=s[i];j++){
            for(int k=v/2;k>=a[i][j];k--){
                dp[j][k] = max(dp[j-1][k], dp[j-1][k-a[i][j]] + a[i][j]);
            }
        }

        ans += max(v-dp[s[i]][v/2], dp[s[i]][v/2]);
        memset(dp, 0, sizeof(dp));
    }
    
    cout << ans << endl;
    return 0;
}
//?