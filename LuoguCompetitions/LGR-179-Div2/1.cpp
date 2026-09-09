#include <bits/stdc++.h>
#define ll long long
#define inf 0xfff
using namespace std;
int main(){
    int n;
    cin>>n;
    ll maxx=-1e+9;
    ll minx=1e+9;
    ll maxy=-1e+9;
    ll miny=1e+9;
    while(n--){
        ll x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        if(max(x1,x2)>maxx)
            maxx=max(x1,x2);
        if(max(y1,y2)>maxy)
            maxy=max(y1,y2);
        if(min(x1,x2)<minx)
            minx=min(x1,x2);
        if(min(y1,y2)<miny)
            miny=min(y1,y2);
    }
    ll s=(maxx-minx)*(maxy-miny);
    cout<<s;
    return 0;
}