//P3954 [NOIP 2017 普及组] 成绩
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int tot = a*0.2 + b*0.3 + c*0.5;

    cout << tot << '\n';    
    
    return 0;
}