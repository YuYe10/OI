//P5734 【深基6.例6】文字处理软件
#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int q;
    cin >> q;
    cin >> s;
    
    while(q--){
        int op;
        cin >> op;
        string ss;
        string tail;
        int a,b;
        int ans;
        switch(op){
            case 1:
            cin >> ss;
            s = s + ss;
            cout << s;
            cout << endl;
            break;

            case 2:
            ss = s;
            cin >> a >> b;
            s = ss.substr(a, b);
            cout << s;
            cout << endl;
            break;

            case 3:
            cin >> a >> ss;
            tail = s.substr(a);
            s.erase(a);
            s = s + ss + tail;
            cout << s;
            cout << endl;
            break;

            case 4:
            cin >> ss;
            ans = s.find(ss);
            cout << ans;
            cout << endl;
            break;

            default:
            break;
        }

    }
    return 0;
}