/* #include <bits/stdc++.h>
#define PI 3.1415926535678
#define e 2.71828182845905
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    int digit = log10(sqrt(2*PI*n)) + n*log10(n/e) + 1;
    printf("%d", digit);
    return 0;
} */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    double ans = 0.0;
    for(int i = 1; i<=n; ++i){
        ans += log10(i);
    }
    int a = ans;
    printf("%d", a + 1);
    return 0;
}