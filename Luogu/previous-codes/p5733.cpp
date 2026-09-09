//P5733 【深基6.例1】自动修正
#include <bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cin>>a;
    int len=a.size();
    for(int i=0;i<=len-1;i++){
        if(a[i]>=97 && a[i]<=123)
        a[i]-=32;
    }
    cout<<a;
    return 0;
}