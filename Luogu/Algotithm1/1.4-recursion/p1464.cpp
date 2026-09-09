// P1464 Function
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mem[25][25][25];
ll w(ll a, ll b, ll c){
    // 条件1: 如果 a <= 0 或 b <= 0 或 c <= 0 就返回值 1
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    
    // 条件2: 如果 a > 20 或 b > 20 或 c > 20 就返回 w(20,20,20)
    if(a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    
    // 检查记忆化数组
    if(mem[a][b][c] != 0) return mem[a][b][c];
    
    // 条件3: 如果 a < b 并且 b < c 就返回 w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c)
    if(a < b && b < c){
        mem[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        return mem[a][b][c];
    }
    
    // 条件4: 其它情况返回 w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1)
    mem[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    return mem[a][b][c];
}
int main(){
    ll a, b, c;
    while(cin >> a >> b >> c){
        if(a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }
    return 0;
}