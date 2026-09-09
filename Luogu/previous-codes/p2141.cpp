#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[101]={0};
    int b[101]={0};//judge k that is it equal to i
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt=0;
    sort(a,a+n);//sort function(cmp)
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=0;k<n;k++){
                if(a[k]==a[j]+a[i] && b[k]==0){cnt++;b[k]=1;}
            }
        }
    }
    cout<<cnt;
    return 0;
}