#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct Node {
    int date;   //该节点保存的数据
    int prev;   //上一个节点的地址
    int next;   //下一个节点的地址
}t1[N], t2[N];

int n, first, last;

int main() {
    scanf("%d%d", &first, &n);
    for (int i = 1; i <= n; i++) {
        int address, date, next;
        scanf("%d%d%d", &address, &date, &next);
        t1[address].date = t2[address].date = date;
        t1[address].next = next;
        if (next == -1) {
            last = address;
        } else {
            t1[next].prev = address;
        }
    }

    int p = last;
    for (;;) {
        if (last == first) {
            t2[last].next = -1;
            break;
        } else {
            t2[last].next = first;
        }
        last = t1[last].prev;

        if (last == first) {
            t2[first].next = -1;
            break;
        } else {
            t2[first].next = last;
        }
        first = t1[first].next;
    }
    
    while (p != -1) {
        printf("%05d %d ", p, t2[p].date);
        if (t2[p].next == -1) {
            printf("-1\n");
        } else {
            printf("%05d\n", t2[p].next);
        }
        p = t2[p].next;
    }
}