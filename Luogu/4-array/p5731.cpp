//P5731 【深基5.习6】蛇形方阵
#include <bits/stdc++.h>
using namespace std;
int main(){
    int ans[15][15]={0};
    int n,num=1,x=1,y=0;;
	cin>>n;
	while (num<=n*n)
	{
		while(y<n&&!ans[x][y+1])ans[x][++y]=num++;
		while(x<n&&!ans[x+1][y])ans[++x][y]=num++;
		while(y>1&&!ans[x][y-1])ans[x][--y]=num++;
		while(x>1&&!ans[x-1][y])ans[--x][y]=num++;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)printf("%3d",ans[i][j]);
		printf("\n");	
	}
    return 0;
}