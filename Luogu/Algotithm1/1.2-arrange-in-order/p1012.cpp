//P1012 [NOIP1998 提高组] 拼数
#include <bits/stdc++.h>
using namespace std;
bool cmp(string a,string b){
    return a + b > b + a;//把优数排在前
}
int main(){
    int n;
    cin>>n;
    string a[25];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    string ans;
    for(auto i:a){
        ans.append(i);
    }
    cout<<ans;
    return 0;
}