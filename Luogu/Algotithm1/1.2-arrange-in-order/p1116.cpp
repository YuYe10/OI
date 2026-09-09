//P1116 车厢重组
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;int ans=0;
    int a[10005]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]) {
                swap(a[i],a[j]);
                ans++;
            }
        }

    }
    cout<<ans;
    return 0;
}

