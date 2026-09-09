//P1421 小玉买文具
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int a,b;
    cin>>a>>b;
    int tot = a*10 + b;
    int per = 19;

    int ans = tot/per;

    cout << ans << '\n';
    
    return 0;
}