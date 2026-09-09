//A - 金币
#include <bits/stdc++.h>
int main(){
    int day=0;int k;int coin=1;
    long long int sum=0;
    std::cin>>k;
    while(k>day){
        if(k-day>coin){
            for(int i=0;i<coin;i++,day++){
            sum+=coin;
            }
            coin++;
        }else{
            for(int i=0;i<k-day;i++,day++){
            sum+=coin;
            }
        }
    }
    std::cout<<sum;
    return 0;
}