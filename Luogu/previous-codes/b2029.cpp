//B2029 大象喝水
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int h, r;
    cin >> h >> r;
    double v = 3.14*r*r*h/1000.00;

    int n = 20/v + 1;
    cout << n << '\n';

    return 0;
}