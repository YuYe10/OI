#include <bits/stdc++.h>
using namespace std;
int I=-1,J=-1;
bool f(int l,int r,int *q){
    for(int i=l;i<=r;i++){
        for(int j=r;j>i;j--){
            if(q[i]!=q[j]){
                I=i;
                J=j;
            }
        }
    }
    if(I==-1 || J==-1)return false;
    return true;
}
int main(){
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int n;
        cin>>n;
        int a[n+1]={0};
        int *p = a;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int q;
        cin>>q;
        for(int i=0;i<q;i++){
            int l;int r;
            cin>>l>>r;
            if(f(l,r,p)){
                cout<<I<<" "<<J<<endl;
                I=J=-1;
            }else{
                cout<<I<<" "<<J<<endl;
                I=J=-1;
            }
        }
    }
    return 0;
}