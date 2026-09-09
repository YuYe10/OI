#include <bits/stdc++.h>
using namespace std;

int val(char c){
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;
}

char toHex(int v){
    if (v < 10) return '0' + v;
    return 'A' + v - 10;
}

int main(){
    string s1, s2;
    while (cin >> s1 >> s2){
        string ans;
        int n1 = s1.size(), n2 = s2.size();
        int n = max(n1, n2);
        
        for (int i = 0; i < n; ++i){
            int d1 = (i < n1) ? val(s1[n1 - 1 - i]) : 0;
            int d2 = (i < n2) ? val(s2[n2 - 1 - i]) : 0;
            ans.push_back(toHex((d1 + d2) % 16));
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}
