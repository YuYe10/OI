//P1036 [NOIP2002 普及组] 选数
#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[25];
long long ans;
bool is_prime(int n){
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return false;
    return true;
}
void dfs(int m, int sum, int s){
    if(m == k){
        if(is_prime(sum))
            ans++;
        return ;
    }
    for(int i = s; i < n; i++)
        dfs(m + 1, sum + a[i], i + 1);
    return ;
}

int main(){
    cin>>n>>k;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    dfs(0, 0, 0);
    cout<<ans;
    return 0;
}