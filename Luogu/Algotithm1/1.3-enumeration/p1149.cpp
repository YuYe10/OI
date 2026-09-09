// P1149 [NOIP 2008 提高组] 火柴棒等式
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> m;

int num_to_stickers(int x){
    int s=0;
    if(x==0)
        return m[0];
    while(x!=0){
        s += m[x%10];
        x/=10;
    }
    return s;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    m[0] = 6;
    m[1] = 2;
    m[2] = 5;
    m[3] = 5;
    m[4] = 4;
    m[5] = 5;
    m[6] = 6;
    m[7] = 3;
    m[8] = 7;
    m[9] = 6;

    int n;
    int ans=0;
    cin >> n;

    n-=4;

    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            if(num_to_stickers(i)+num_to_stickers(j)+num_to_stickers(i+j)==n)
                ans++;
        }
    }

    cout << ans;
    return 0;
}