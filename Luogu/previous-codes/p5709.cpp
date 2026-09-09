//P5709 【深基2.习6】Apples Prologue / 苹果和虫子
#include <bits/stdc++.h>
int main(){
    int m,t,s;
    std::cin>>m>>t>>s;
    if(t==0 && s!=0){std::cout<<0;return 0;}
    if(t==0 && s==0){std::cout<<m;return 0;}
    if(s%t==0 && s/t>=m){std::cout<<0;return 0;}
    if(s%t!=0 && s/t+1>=m){std::cout<<0;return 0;}
    if(s<=t){std::cout<<m-1;return 0;}
    if(s%t==0){std::cout<<m-s/t;return 0;}
    else{std::cout<<m-s/t-1;return 0;}
}