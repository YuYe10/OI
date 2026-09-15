#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;

using namespace std;

const int N = 1e5+5;
int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    int ans = 1e9;
    ll prev = -1e15;
    vector<int> cur;

    for(int i = 0; i < n; ){
        int j = i;
        while(j < n && a[j] == a[i]) j++;
        ll v = a[i];
        int c = j - i;

        if(v != prev + 1){
            if(!cur.empty()) ans = min(ans, cur[0]);
            cur.clear();
        }

        int g = cur.size();
        if(g >= c){
  
            if(g > c) ans = min(ans, cur[c]);
            cur.resize(c);
            for(int &x : cur) x++;
        }else{

            vector<int> nxt(c - g, 1);
            for(int x : cur) nxt.push_back(x + 1);
            cur.swap(nxt);
        }

        prev = v;
        i = j;
    }

    ans = min(ans, cur[0]);
    cout << ans << '\n';
    return 0;
}
