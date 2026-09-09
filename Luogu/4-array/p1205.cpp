#include <bits/stdc++.h>
#define maxn 100
using namespace std;
int n;
char a[maxn+1][maxn+1];
char t[maxn+1][maxn+1];
char b[maxn+1][maxn+1];
char ans[maxn+1][maxn+1];
bool t90(void){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            t[j][n-i+1]=a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(t[i][j]!=ans[i][j])return 0;
        }
    }
    return 1;
}
bool t180(void){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            t[n-i+1][n-j+1]=a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(t[i][j]!=ans[i][j])return 0;
        }
    }
    return 1;
}
bool t270(void){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            t[n-j+1][i]=a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(t[i][j]!=ans[i][j])return 0;
        }
    }
    return 1;
}
bool reflect(void){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            t[i][n-j+1]=a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(t[i][j]!=ans[i][j])return 0;
        }
    }
    return 1;
}
bool combine(void){
        reflect();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=t[i][j];    
            }
        }
        if(t90())return 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=t[i][j];
                
            }
        }
        if(t180())return 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=t[i][j];    
            }
        }
        if(t270())return 1;
    return 0;
}
bool donothing(void){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j]!=ans[i][j])return 0;
        }
    }
    return 1;
}
void process(void)
{
    if(t90())
    {
        cout<<1;
        return ;
    }
    if(t180())
    {
        cout<<2;
        return ;
    }
    if(t270())
    {
    	cout<<3;
    	return ;
	}
	if(reflect())
	{
		cout<<4;
		return ;
	}
	if(combine())
	{
		cout<<5;
		return ;
	}
	if(donothing())
	{
		cout<<6;
		return ;
	}
	cout<<7;
}
int main(){
    scanf("%d",&n);
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
                a[i][j]=0;
                t[i][j]=0;
                b[i][j]=0;
                ans[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
             {
             	cin>>a[i][j];
             	b[i][j]=a[i][j];
        	 }
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                  cin>>ans[i][j];
            }
    }
    process();
    return 0;
}