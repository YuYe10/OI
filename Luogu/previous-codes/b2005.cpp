//B2005 字符三角形
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    char c;
    cin >> c;
    for(int j = 2; j >= 0; --j){
        for(int i = j; i > 0 ; --i){
            cout << ' ';
        }

        for(int i = 5-2*j; i > 0; --i){
            cout << c;
        }   

        cout << '\n';
    }

    return 0;
}