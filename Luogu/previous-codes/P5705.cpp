//P5705 【深基2.例7】数字反转
#include <bits/stdc++.h>
using namespace std;
int main(){
    float n;
    scanf("%f",&n);
    int m=n*10;
    int ret=0;
    int digit;
    while(m!=0){
        digit=m%10;
        ret=ret*10+digit;
        m/=10;
    }
    n=ret/1000.000;
    printf("%.3f",n);
    return 0;
}