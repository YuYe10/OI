//P5726 【深基4.习9】打分
#include <bits/stdc++.h>
using namespace std;
void qsort(int l,int r);
int n;
double a[1001];
int main()
{
    using namespace std;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    qsort(1,n);
    a[1]=0;
    a[n]=0;
    double s=0;
    for(int i=1;i<=n;i++){
        s+=a[i];
    }
    double average=s/(n-2);
    printf("%.2lf",average);
    return 0;
}

void qsort(int l,int r){
    int i,j;
    double p,mid;
    i=l;j=r;
    mid=a[(l+r)/2];
    do
    {
        while(a[i]<mid)i++;
        while(a[j]>mid)j--;
        if(i<=j){
            p=a[i];a[i]=a[j];a[j]=p;
            i++;j--;
        }
    } while (i<=j);
    if(l<j) qsort(l,j);
    if(i<r) qsort(i,r);
    
}