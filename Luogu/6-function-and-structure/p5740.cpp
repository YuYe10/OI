//P5740 【深基7.例9】最厉害的学生
#include <bits/stdc++.h>
using namespace std;
struct Student{
    string name;
    int id;
    int Ch;
    int Math;
    int En;
}s[1010];
int main(){
    int n;int maxn=-1,imaxn;int sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        s[i].id=i;
        cin>>s[i].name>>s[i].Ch>>s[i].Math>>s[i].En;
        sum=s[i].Ch+s[i].Math+s[i].En;
        if(sum>maxn){
            imaxn=i;
            maxn=sum;
        }
    }
    cout<<s[imaxn].name<<" "<<s[imaxn].Ch<<" "<<s[imaxn].Math<<" "<<s[imaxn].En<<endl;
    return 0;
}