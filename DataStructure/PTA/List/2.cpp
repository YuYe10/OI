#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct Node {
    int date;   
    int next;   
}t1[N], t2[N], t3[N];

int n, first, first2, first3;
bool flag[N];

int main() {
    scanf("%d%d", &first, &n);
    for (int i = 1; i <= n; i++) {
        int address, date, next;
        scanf("%d%d%d", &address, &date, &next);
        t1[address].date = t2[address].date = t3[address].date = date; 
        t1[address].next = next;
    }

    int p2 = -1, p3 = -1;
    first2 = first3 = -1;
    for (int p = first; p != -1; p = t1[p].next) {
        if (flag[abs(t1[p].date)]) {
            if (p3 == -1) {
                first3 = p3 = p;
                t3[p3].next = -1;
            } else {
                t3[p3].next = p;
                p3 = p;
                t3[p3].next = -1;
            }
        } else {
            if (p2 == -1) {
                first2 = p2 = p;
                t2[p2].next = -1;
            }
            t2[p2].next = p;
            p2 = p;
            t2[p2].next = -1;
            flag[abs(t2[p2].date)] = 1;
        }
    }
    
    int p = first2;
    while (p != -1) {
        printf("%05d %d ", p, t2[p].date);
        if (t2[p].next == -1) {
            printf("-1\n");
        } else {
            printf("%05d\n", t2[p].next);
        }
        p = t2[p].next;
    }

    p = first3;
    while (p != -1) {
        printf("%05d %d ", p, t3[p].date);
        if (t3[p].next == -1) {
            printf("-1\n");
        } else {
            printf("%05d\n", t3[p].next);
        }
        p = t3[p].next;
    }
}