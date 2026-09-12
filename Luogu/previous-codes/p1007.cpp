#include <bits/stdc++.h>
using namespace std;

int main(){
    int l, n;
    scanf("%d\n%d\n", &l, &n);

    int mint=0, maxt=0;

    for(int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);

        mint = max(mint, min(x, l+1-x));
        maxt = max(maxt, max(x, l+1-x));
    }

    printf("%d %d\n", mint, maxt);
    return 0;
}