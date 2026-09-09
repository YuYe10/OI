#include<bits/stdc++.h>
#define ll long long

using namespace std;

stack<ll> s;
ll a[100010];
ll sum[100010];
ll ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i) sum[i]=sum[i-1]+a[i];
        else sum[i]=a[i];
    }

    for(int i=0;i<=n;){
        if(s.empty() || a[s.top()] <= a[i]) s.push(i++);
        else{
            int t = s.top();
            s.pop();
            if(s.empty()) ans = max(ans, sum[i-1]*a[t]);
            else ans = max(ans, (sum[i-1] - sum[s.top()])*a[t]);
        }
    }
    cout << ans;
}