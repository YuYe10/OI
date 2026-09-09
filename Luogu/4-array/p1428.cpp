//P1428 小鱼比可爱
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    const int N=n;
    int a[N+1]={0};
    int ans[N+1]={0};
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    ans[1]=0;
    for(int j=2;j<=n;j++){
        for(int i=1;i<j;i++){
            if(a[i]<a[j])ans[j]++;
        }
    }
    for(int i=1;i<n;i++){
        printf("%d ",ans[i]);
    }
    printf("%d",ans[N]);
    return 0;
}