//P3392 涂条纹
#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    char a[51][51];

    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }

    int min_ops = 1e9;
    
    for(int i = 1; i <= n-2; ++i){
        for(int j = i+1; j <= n-1; ++j){
            int ops = 0;

            for(int r = 1; r <= i; ++r)
                for(int c = 1; c <= m; ++c)
                    if(a[r][c] != 'W') ops++;

            for(int r = i+1; r <= j; ++r)
                for(int c = 1; c <= m; ++c)
                    if(a[r][c] != 'B') ops++;

            for(int r = j+1; r <= n; ++r)
                for(int c = 1; c <= m; ++c)
                    if(a[r][c] != 'R') ops++;

            min_ops = min(min_ops, ops);
        }
    }

    cout << min_ops;
    
    return 0;
}