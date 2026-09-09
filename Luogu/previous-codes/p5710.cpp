//P5710 【深基3.例2】数的性质
#include <bits/stdc++.h>
int main(){
    int x;
    int a[5]={0};
    std::cin>>x;
    if(x%2==0){
        a[2]=1;
        if(x>4 && x<=12){
            a[1]=1;
        }else{
            a[3]=1;
        }
    }else{
        if(x>4 && x<=12){
            a[2]=a[3]=1;
        }else{
            a[4]=1;
        }
    }
    for(int i=1;i<=4;i++){
        std::cout<<a[i]<<" ";
    }
    return 0;
}