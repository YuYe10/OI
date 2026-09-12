#include <bits/stdc++.h>
using namespace std;

string s;

// 把 a,a+1 位置上的一对棋子，移到 b,b+1 的空位上
void mv(int a, int b) {
    swap(s[a], s[b]);
    swap(s[a + 1], s[b + 1]);
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;


    s = string(n, 'o') + string(n, '*') + "--";
    cout << s << '\n';

    // 每次把规模从 k 缩小到 k-1，直到 k=4
    for (int k = n; k >= 5; --k) {
        mv(k - 1, 2 * k);      // 把边界 "o*" 移到末尾空位
        mv(2 * k - 2, k - 1);  // 把最后两个 "*" 移到空位
    }

    // k = 4 的基础情形，固定五步
    mv(3, 8);
    mv(7, 3);
    mv(1, 7);
    mv(6, 1);
    mv(0, 6);

    return 0;
}