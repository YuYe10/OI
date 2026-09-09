/*前缀和+dp*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    int a[1000005];
    int sum[1000005];
    int dp[1000005];
    int ans=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        sum[0]=0;
        ans=0;
        for(int i=1;i<=n;i++)
        {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
        }
        dp[m]=0;
        for(int i=1;i<=m;i++)
            dp[m]=dp[m]+i*a[i];
        ans=dp[m];
        for(int i=m+1;i<=n;i++)
        {
            dp[i]=dp[i-1]-(sum[i-1]-sum[i-1-m])+m*a[i];
            ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}