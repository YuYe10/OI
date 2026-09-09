#include<bits/stdc++.h>
using namespace std;
 
int n,k,a[300010],d[300010];
 
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);cin.tie(0);

    int n,k;
    cin >> n >> k; 
    for(int i=1;i<=n;++i){
        cin >> a[i];
        d[i] = a[i] - a[i-1];
    }
    sort(d+1,d+n+1);
    int ans = a[n] - a[1];
    for (int i = 0; i < k-1; i++)
    {
        ans -= d[n-i];
    }
    
    cout << ans;
}