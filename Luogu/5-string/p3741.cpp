//P3741 honoka的键盘
#include <bits/stdc++.h>
using namespace std;
int main(){
    string a;
    int n,cnt=0;
    cin>>n;
    cin>>a;
    for(int i=0;i<n;i++){
        if(a[i]=='V' && a[i+1]=='K'){
            a[i]=a[i+1]='T';cnt++;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]!='T' && a[i]==a[i+1]){
            cnt++;break;
        }
    }
    cout<<cnt;
    return 0;
}