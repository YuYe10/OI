//P1075 [NOIP 2012 普及组] 质因数分解
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x){
    if(x == 1)
        return 0;
    if(x < 4)
        return 1;
    
    for(int i = 2; i*i < x; ++i){
        if(x%i == 0)
            return 0;
    }

    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout .tie(0);

    int n;
    cin >> n;

    for(int i=2; i*i <= n; i++){
        if(isPrime(i)){
            if(n%i == 0){
                cout << n/i;
            }
        }
    }
    return 0;
}