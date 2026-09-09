#include <bits/stdc++.h>
#define ll long long
#define inf 0xfff
using namespace std;
int main(){
    int n,k,p,q;
    cin>>n>>k>>p>>q;
    int cnt=0;
    while(p*(n+cnt)<k*q){
        cnt++;
    }
    cout<<cnt;
    return 0;
}