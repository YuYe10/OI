#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string s;
int pos;

// 从 pos 开始解析，直到遇到 ']'（或字符串末尾）为止，返回解压后的字符串。
// 解析到 ']' 时会自动跳过它。
string solve() {
    string res;
    while (pos < (int)s.size()) {
        if (s[pos] == ']') {
            pos++;          // 跳过 ']'
            return res;
        } else if (s[pos] == '[') {
            pos++;          // 跳过 '['
            int num = 0;
            while (pos < (int)s.size() && isdigit(s[pos])) {
                num = num * 10 + (s[pos] - '0');
                pos++;
            }
            string inner = solve();           // 递归解析到匹配的 ']'
            for (int i = 0; i < num; i++) res += inner;
        } else {
            res += s[pos];
            pos++;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    pos = 0;
    cout << solve() << '\n';
    return 0;
}
