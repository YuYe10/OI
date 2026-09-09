//P2615 [NOIP2015 提高组] 神奇的幻方
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int n;
    cin>>n;
    int a[n+2][n+2];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=0;
        }
    }
    a[1][(n+1)/2]=1;
    int k;int x = 1;
    int y=((n+1)/2);
    	for(int k=2;k<=n*n;k++){
		if(x==1&&y!=n){
			a[n][y+1]=k;
			x=n;
			y+=1; 
		}else if(x!=1&&y==n){
			a[x-1][1]=k;
			x-=1;
			y=1;
		}else if(x==1&&y==n){
			a[x+1][n]=k;
			x+=1;
			y=n;
		}else{
			if(a[x-1][y+1]==0){
				a[x-1][y+1]=k;
				x-=1;
				y+=1;
			}else{
				a[x+1][y]=k;
				x+=1;
			}
		}
	}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}