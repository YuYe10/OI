//P1614 爱与愁的心痛
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,a[100005]={0},sum=100005,s=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n-m+1;i++)
    {
    	for (int j=1;j<=m;j++)s+=a[i+j-1];
    	if(s<sum)sum=s;
        s=0;
    }
    cout<<sum;
    return 0;
}