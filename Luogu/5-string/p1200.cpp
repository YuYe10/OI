//P1200 [USACO1.1] 你的飞碟在这儿 Your Ride Is Here
#include <bits/stdc++.h>
using namespace std;
int main(){
    char a[10];
    char ans[10];
    cin>>ans;cin>>a;
    int mul1=1,mul2=1;
    int i=-1,j=-1;
    while(ans[++i]!=0){
        mul1*=(ans[i]-'A'+1);
    }
    while(a[++j]!=0){
        mul2*=(a[j]-'A'+1);
    }
    if(mul1%47==mul2%47)printf("GO");
    else printf("STAY");
    return 0;
}