//P3741 honoka的键盘
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    char a[105];
    scanf("%s",a);
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(a[i]=='V' && a[i+1]=='V'){
            cnt++;i++;
        }
        if(a[i]=='V' && a[i+1]=='K'){
            cnt++;i++;
        }
        if(a[i]=='K' && a[i+1]=='K'){
            cnt++;i++;
        }
    }
    cout<<cnt;
    return 0;
}