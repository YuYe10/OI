// P6033 [NOIP 2004 提高组] 合并果子 加强版
// 思路：哈夫曼树，每次合并当前最小的两堆。
//   n <= 1e7 且 a_i <= 1e5，于是
//     1) 用桶计数代替排序，得到"队列 1"（单调不降的原始数据，懒展开）；
//     2) 合并出的新堆放进"队列 2"，其同样单调不降，于是不必用堆。

#include <bits/stdc++.h>
typedef long long ll;

namespace IO {
const int BUFSIZE = 1 << 20;
char buf[BUFSIZE];
int len = 0, pos = 0;

inline char gc() {
    if (pos == len) {
        len = (int)fread(buf, 1, BUFSIZE, stdin);
        pos = 0;
        if (len <= 0) return 0;  // EOF
    }
    return buf[pos++];
}

inline int readInt() {
    int x = 0;
    char c = gc();
    while (c < '0' || c > '9') {
        if (!c) return 0;  // EOF 保护
        c = gc();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = gc();
    }
    return x;
}
}  // namespace IO

const int MAXA = 100000;
int cnt[MAXA + 2];  // 值为 v的堆

// 合并产生的新堆，用环形缓冲区实现。
std::vector<ll> q2;

int main() {
    int n = IO::readInt();
    for (int i = 0; i < n; i++) cnt[IO::readInt()]++;
    if (n <= 1) {  // 只有一堆，无需合并
        printf("0\n");
        return 0;
    }

    q2.resize(n / 2 + 4);
    const int cap = (int)q2.size();
    int head = 0, tail = 0;  // 环形缓冲区，有效元素为 qn 个
    int qn = 0;
    int p = 1;  // 指向当前最小的非空桶

    ll ans = 0;
    for (int i = 1; i < n; i++) {  // 恰好合并 n-1 次
        ll x = 0, y = 0;
        for (int k = 0; k < 2; k++) {
            while (p <= MAXA && cnt[p] == 0) p++;
            ll v;
            if (qn > 0 && (p > MAXA || q2[head] < p)) {
                v = q2[head];  // 队头更小，取队列 2
                if (++head == cap) head = 0;
                qn--;
            } else {
                v = p;  // 相等时优先取队列 1，结果等价
                cnt[p]--;
            }
            if (k == 0) x = v; else y = v;
        }
        ans += x + y;
        q2[tail] = x + y;
        if (++tail == cap) tail = 0;
        qn++;
    }

    printf("%lld\n", ans);
    return 0;
}
