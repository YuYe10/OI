#include <bits/stdc++.h>
using namespace std;
int t,n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }

        int ans;
        sort(a.begin(), a.end());

        if(n%2 != 0){
            int k = (n + 1)/2;
            ans = a[n-k];   
        }

        if(n%2 == 0){
            int k = (n + 1)/2;
            ans = a[n-k];  
        }
        
        cout << ans << endl;
    }
    return 0;
}