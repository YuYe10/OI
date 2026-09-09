#include <bits/stdc++.h>
int main()
{
    using namespace std;
    const int N = 50;
    int a[N];
    int n;
    cin>>n;
    //cout<<sizeof(n);
    for(int i=1;i<n+1;i++){
        a[i-1]=i;
        //cout<<a[i-1]<<" ";
    }
    int cnt=0;
    long long sum=0;
    long long ret=1;
    while(cnt<n){
        for(int i=0;i<=cnt;i++){
            ret*=a[i];
        }
        cnt++;
        sum+=ret;
        ret=1;
    }
    cout<<sum<<endl;
    return 0;
}