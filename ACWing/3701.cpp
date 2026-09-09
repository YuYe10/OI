#include <bits/stdc++.h>
using namespace std;

int main(){
    // 先读全部查询，确定最大上界
    vector<pair<int,int>> q;
    int a, b;
    int maxB = 0;
    while (cin >> a >> b){
        q.push_back({a, b});
        maxB = max(maxB, b);
    }

    // 埃氏筛到 maxB，prime[i] 表示 i 是否为质数
    vector<char> prime(maxB + 1, true);
    if (maxB >= 0) prime[0] = false;
    if (maxB >= 1) prime[1] = false;
    for (long long i = 2; i * i <= maxB; ++i){
        if (prime[i]){
            for (long long j = i * i; j <= maxB; j += i)
                prime[j] = false;
        }
    }

    // 质数个数的前缀和
    vector<int> pre(maxB + 1, 0);
    for (int i = 1; i <= maxB; ++i)
        pre[i] = pre[i-1] + prime[i];

    for (auto &p : q){
        a = p.first; b = p.second;
        int total = b - a + 1;
        int primes = pre[b] - pre[a-1];
        // 1 既不是质数也不是合数，若在区间内需减去
        int one = (a <= 1 && 1 <= b) ? 1 : 0;
        cout << total - primes - one << endl;
    }
    return 0;
}
