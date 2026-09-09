//P1088 [NOIP 2004 普及组] 火星人
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    vector<int> v;
    int n, m;
    cin >> n >> m;

    while(n--){
        int x;
        cin >> x;
        v.push_back(x);
    }

    while(m--)
        next_permutation(v.begin(), v.end());

    for(auto i:v)
        cout << i << ' ';
    cout << endl;

    return 0;
}