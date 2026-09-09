//P1177 【模板】排序
#include <bits/stdc++.h>
using namespace std;
unsigned long long int a[100010]={0};
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n-1;i++){
        cout<<a[i]<<' ';
    }
    cout<<a[n-1];
    return 0;
}
