//P5736 【深基7.例2】质数筛
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x){
    if(x==1) return false;
    if(x==2 || x==3)return true;
    if(x%6!=1 && x%6!=5)return false;
    for(int i=5;i*i<=x;i++){
        if(x%i==0 || x%(i+2)==0)return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(isPrime(a))cout<<a<<" ";
    }
    return 0;
}