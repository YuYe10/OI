//P1427 小鱼的数字游戏
#include <bits/stdc++.h>
std::stack<long long> a;
int main(){
    long long x;
    while(true){
        scanf("%lld",&x);
        if(x)a.push(x);
        else break;
    }
    while(!a.empty()){
        std::cout<<a.top()<<" ";
        a.pop();
    }
    return 0;
}