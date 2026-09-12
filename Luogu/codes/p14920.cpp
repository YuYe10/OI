#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
ll dp[250005]; // dp[j] = 获得恰好 j 点攻击力所需的最小金币数
int a[505], c[505];

int main(){
    int n; ll k;
    scanf("%d%lld", &n, &k);

    int sum = 0;
    for(int i=1; i<=n; i++){
        scanf("%d%d", &a[i], &c[i]);
        sum += a[i];
    }

    fill(dp, dp + sum + 1, INF);
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=sum; j>=a[i]; j--){
            if(dp[j-a[i]] != INF)
                dp[j] = min(dp[j], dp[j-a[i]] + c[i]);
        }
    }

    for(int j=sum; j>=0; j--){
        if(dp[j] <= k){
            printf("%d\n", j);
            break;
        }
    }
    return 0;
}
