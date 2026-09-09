//P3654 First Step (ファーストステップ)
#include <bits/stdc++.h>
using namespace std;
char a[105][105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int ans=0;
    int r,c,k;
    cin >> r >> c >> k;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> a[i][j];
        }
    }
    // 横向搜索
    for(int i=0; i<c; i++){
        int flag=true;
        for(int j=0; j<r; j++){
            for(int l=0; l<k; l++){
                if(a[i][j+l] != '.'){
                    flag = false;
                    break;
                }
            }

            if(flag){
                ans++;
            }

            flag = true;
        }
    }
    // 纵向搜索
    for(int i=0; i<r; i++){
        int flag=true;
        for(int j=0; j<c; j++){
            for(int l=0; l<k; l++){
                if(a[j+l][i] != '.'){
                    flag = false;
                    break;
                }
            }

            if(flag){
                ans++;
            }

            flag = true;
        }
    }

    if(k==1){
        cout << ans/2;
    }
    else{
        cout << ans;
    }
    return 0;
}