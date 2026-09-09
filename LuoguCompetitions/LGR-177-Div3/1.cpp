//P10244 String Minimization
#include <bits/stdc++.h>
#define ll long long
#define inf 0xfff
using namespace std;
int main(){
    int n;
    cin>>n;
    string a,b,c,d;string min;
    for(int i=0;i<n;i++){
        min.push_back('z');
    }
    cin>>a>>b>>c>>d;
    for(int i=0;i<n;i++){
        if(a[i]>=c[i]){
            swap(a[i],c[i]);
            swap(b[i],d[i]);
            if(b<=min){
                min=b;
            }
            else{
                if(a[i]==c[i]){
                    swap(a[i],c[i]);
                    swap(b[i],d[i]);
                }
            }
        }else
            break;
    }
    cout<<b;
    return 0;
}