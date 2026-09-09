#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    
    for (int i = 0; i < k; i++){
        string x;
        cin >> x;
        mp[x]++;
    }

    for (int i = 0; i < q; ++i){
        string x;
        cin >> x;
        if (mp.find(x) != mp.end()) {
            cout << mp[x] << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}