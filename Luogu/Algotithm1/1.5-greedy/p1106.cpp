#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    string s;
    int k;
    cin >> s >> k;

    string st;
    for(char c : s){
        while(k > 0 && !st.empty() && st.back() > c){
            st.pop_back();
            k--;
        }
        st.push_back(c);
    }
    while(k-- > 0) st.pop_back();

    int i = 0;
    while(i + 1 < st.size() && st[i] == '0') i++;
    cout << st.substr(i) << '\n';

    return 0;
}
