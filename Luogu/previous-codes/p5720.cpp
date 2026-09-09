#include <bits/stdc++.h>
int main()
{
    int a;
    scanf("%d",&a);
    int cnt=1;
    while(a>1){
        a/=2;
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}