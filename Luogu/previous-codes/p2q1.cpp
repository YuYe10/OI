#include <bits/stdc++.h>
using namespace std;
int a[110],b[110],c[220];
string s1,s2;
int main()
{
    cin>>s1>>s2;
    //逆向存储两个数组
    for (int i=0;i<s1.size();i++) a[i] = s1[s1.size()-1-i]-'0';
    for (int j=0;j<s2.size();j++) b[j] = s2[s2.size()-1-j]-'0';
    //高精度*高精度
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            c[i+j]+=a[i]*b[j];
        }
    }
    //进位
    for(int i=0;i<100;i++){
        if(c[i]>9){
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    }
    //逆向输出，消除前导0.
    for(int i=210;i>0;i--){
        int signal=0;
        if(c[i]!=0){signal=1;}
        if(signal){cout<<c[i];}
    }
    cout<<c[0];
    return 0;
}