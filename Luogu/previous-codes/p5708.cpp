//P5708 【深基2.习2】三角形面积
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    double a, b, c;
    cin >> a >> b >> c;
    double s = (a + b + c) / 2;
    cout << fixed << setprecision(1) << sqrt(s * (s - a) * (s - b) * (s - c)) << '\n';
    return 0;
}