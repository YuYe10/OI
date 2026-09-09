#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    double a[1001];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int t;
    int i,j;
    i=1;
    /*for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            if(a[j]<a[j+1]){
                t=a[j];a[j]=a[j+1];a[j+1]=t;
            }
        }
    }*/
    bool bo=true;
    do{
        bo=true;
        for(j=1;j<=n-i;j++){
                if(a[j]<a[j+1]){
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                    bo=false;
                }
            }
        i++;
    }while(!bo);
    a[1]=0;
    a[n]=0;
    double s=0;
    for(i=1;i<=n;i++){
        s+=a[i];
    }
    double average=s/(n-2);
    printf("%.2lf",average);
    return 0;
}
