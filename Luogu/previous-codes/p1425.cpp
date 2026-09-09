//P1425 小鱼的游泳时间
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    a*=60;c*=60;a+=b;c+=d;
    int delta_t=c-a;
    cout<<delta_t/60<<" "<<delta_t%60;
    return 0;
}