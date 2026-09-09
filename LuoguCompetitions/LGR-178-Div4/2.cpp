#include <bits/stdc++.h>
#define ll long long
#define inf 0xfff
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        ll k=y-x;
        
        if(k>0 && k<=2*12000){
            cout<<5<<endl;
        }else if(k>2*12000 && k<=2*16000){
            cout<<6<<endl;
        }else if(k>2*16000 && k<=2*24000){
            cout<<8<<endl;
        }else if(k>2*24000 && k<=2*32000){
            cout<<11<<endl;
        }else if(k>2*32000 && k<=2*48000){
            cout<<13<<endl;
        }else{
            ll cnt=1;
            while(k>cnt*2*48000){
                cnt++;
            }
            cout<<13*cnt<<endl;
        }
    }
    return 0;
}