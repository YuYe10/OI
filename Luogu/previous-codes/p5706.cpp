//P5706 【深基2.例8】再分肥宅水
#include <bits/stdc++.h>
using namespace std;
int main(){
    float t;int n;
    cin>>t>>n;
    int bottles=n*2;
    float average=t/n*1.000;
    printf("%.3f\n",average);
    cout<<bottles;
    return 0;
}