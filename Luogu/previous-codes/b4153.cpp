//B4153
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 0, c = getchar();
    while (c != EOF && (c < '0' || c > '9')) c = getchar();
    while (c >= '0' && c <= '9') { n = n * 10 + (c - '0'); c = getchar(); }

    int shift = n + 1;
    vector<int> sum(2 * n + 3, 0);
    long long ans = 0, a = 0;
    int cur = 0;
    sum[cur + shift]++;

    for(int i = 0; i < n; i++) {
        while ((c = getchar()) != EOF && c != '0' && c != '1');
        if(c == '1') {
            a += sum[cur + shift];
            cur++;
        } else {
            a -= sum[cur + shift - 1];
            cur--;
        }
        ans += a;
        sum[cur + shift]++;
    }
    printf("%lld\n", ans);

    return 0;
}
