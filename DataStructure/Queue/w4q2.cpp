#include <bits/stdc++.h>  
#define ms(l) memset(l, 0, sizeof(l))
using namespace std;  

int main() {
    int n,m,cnt,l[1024];
    ms(l);
    queue<pair<int, int>> q;

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> l[i];
        q.push({l[i], i});
    }
    cnt = 0;
    int maxn = n-1;
    sort(l, l+n);
    while(true && !q.empty()){
        if(l[maxn] != q.front().first){
            q.push(q.front());
            q.pop();
        }else{
            cnt++;
            if(m-1 == q.front().second){
                cout << cnt;
                break;
            }else{
                q.pop();
                maxn--;
            }
        }
    }
    return 0;  
} 