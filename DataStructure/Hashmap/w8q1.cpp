#include<bits/stdc++.h>
using namespace std;
 
int n,m,x;
int mp[2000000];
 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",&x);
		mp[x%1000001+7]=i;
	}
	for(int i=1;i<=m;i++) {
		scanf("%d",&x);
		printf("%d\n",mp[x%1000001+7]);
	}
	return 0;
}