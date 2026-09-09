//P1271 【深基9.例1】选举学生会
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    vector<int> v;
    cin >> n >> m;
    int _m = m;
    while(_m--){
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for(auto _v:v){
        cout << _v << ' ';
    }
    cout << endl;
    return 0;
}