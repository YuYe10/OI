#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> a, b, c;
    int x;
    while (scanf("%d", &x) && x != -1) {
        a.push_back(x);
    }
    while (scanf("%d", &x) && x != -1) {
        b.push_back(x);
    }

    int n = a.size(), m = b.size(), l1 = 0, l2 = 0;
    while (l1 < n && l2 < m) {
        if (a[l1] == b[l2]) {
            c.push_back(a[l1]);
            l1++, l2++;
        } else if (a[l1] < b[l2]) {
            l1++;
        } else if (a[l1] > b[l2]) {
            l2++;
        }
    }

    if (c.empty()) {
        printf("NULL");
    } else {
        printf("%d", c[0]);
        for (int i = 1; i < c.size(); i++) {
            printf(" %d", c[i]);
        }
    }
}