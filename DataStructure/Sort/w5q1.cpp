#include <cstdio>
#include <algorithm>
const int MAX_SIZE = 105;
int a[MAX_SIZE];
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int cnt = 0;
    for(int i = 0; i < n; i+=2){
        cnt = cnt + a[i+1] - a[i];
    }
    printf("%d", cnt);
    return 0;
}