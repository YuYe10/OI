//P1598 垂直柱状图
#include <bits/stdc++.h>
using namespace std;
int ans[27]={0};
int main(){
    string a[5];
    int maxn=0;
    for(int i=1;i<=4;i++){
        getline(cin,a[i]);
    }
    for(int i=1;i<=4;i++){
        for(auto j:a[i]){
            if(j>='A' && j<='Z'){
                ans[j-'A'+1]++;
            }
            else continue;
        }
    }
    for(int i=1;i<=26;i++)maxn=max(ans[i],maxn);
    for(int i=maxn;i>0;i--){
        for(int j=1;j<=25;j++){
            if(ans[j]>=i)printf("* ");
            else printf("  ");
        }
        if(ans[26]>=i)printf("*");
        else printf(" ");
        printf("\n");
    }
    for(int i=0;i<25;i++){
        printf("%c ",'A'+i);
    }
    printf("Z");
    return 0;
}