#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;char ch;int flag=0;int sign=1;
    int a[11][11]={0};int ans[11][11]={0};int b[11][11]={0};
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ch;
            if(ch=='@'){
            a[i][j]=1;
            b[i][j]=1;
            }/*else if(ch=='-'){
            a[i][j]=2;
            b[i][j]=2;
            }*/
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ch;
            if(ch=='@')
            ans[i][j]=1;
            /*else if(ch=='-')
            ans[i][j]=2;*/
        }
    }
    return 0;
}