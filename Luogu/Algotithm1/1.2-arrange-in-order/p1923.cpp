//P1923 【深基9.例4】求第 k 小的数
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
void mysort(int l,int r,int *p){
    int i=l,j=r,mid=a[(l+r)/2];
    do{
        while(mid<a[j])j--;
        while(mid>a[i])i++;
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(*p<=j)mysort(l,j,p);
    else if(*p>=i)mysort(i,r,p);
    else{
        printf("%d",a[j+1]);
        exit(0);//正常退出
    }
}
int main(){
    int n,N,k;
    scanf("%d%d",&n,&k);//scamf优化速度
    int *q=&k;
    N=n;
    int x;
    while(n--){
        scanf("%d",&x);
        a.push_back(x);
    }
    mysort(0,N-1,q);
    return 0;
}