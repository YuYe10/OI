//P5727 【深基5.例3】冰雹猜想
#include <bits/stdc++.h>
using namespace std;
stack<long long> a;
int main(){
    long long x;
    cin>>x;
    while(x!=1){
        a.push(x);
        if(x%2==0)x/=2;
        else x=x*3+1;
    }
    a.push(x);
    while(!a.empty()){
        cout<<a.top()<<" ";
        a.pop();
    }
    return 0;
}