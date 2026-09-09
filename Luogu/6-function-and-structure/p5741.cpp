//P5741 【深基7.例10】旗鼓相当的对手 - 加强版
#include <bits/stdc++.h>
using namespace std;
struct Student{
    string name;
    int Ch;
    int Math;
    int En;
    int sum;
}s[1010];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i].name>>s[i].Ch>>s[i].Math>>s[i].En;
        s[i].sum=s[i].Ch+s[i].Math+s[i].En;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int a1=abs(s[i].Ch-s[j].Ch);
            int a2=abs(s[i].Math-s[j].Math);
            int a3=abs(s[i].En-s[j].En);
            int a4=abs(s[i].sum-s[j].sum);
            if(a1<=5 && a2<=5 && a3<=5 && a4<=10){
                if(s[i].name>s[j].name)
                    cout<<s[j].name<<" "<<s[i].name<<endl;
                else
                    cout<<s[i].name<<" "<<s[j].name<<endl;
            }
        }
    }
    return 0;
}