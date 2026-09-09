//P1553 数字反转（升级版）
#include <bits/stdc++.h>
using namespace std;
string RF(string s){
    int fzero=0;
    reverse(s.begin(),s.end());
    if(s=="0")return "0";
    else{
        for(int i=0;i<s.length();i++){
            if(s[i]!='0')break;
            fzero++;
        }
    }
    s.erase(s.begin(),s.begin()+fzero);
    return s;
}
string RB(string s){
    int bzero=0;
    reverse(s.begin(),s.end());
    if(s=="0")return "0";
    else{
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!='0')break;
            bzero++;
        }
    }
    s.erase(s.end()-bzero,s.end());
    return s;
}
int main(){
    string a;
    int flag=1;
    cin>>a;
    if(a.find(".")!=string::npos)flag=2;
    if(a.find("/")!=string::npos)flag=3;
    if(a.find("%")!=string::npos)flag=4;
    if(flag==1){
        cout<<RF(a);
    }
    if(flag==2){
        string front,back;
        front=a.substr(0,a.find("."));
        back=a.substr(a.find(".")+1,a.length()-1);
        cout<<RF(front)<<"."<<RB(back);
    }
    if(flag==3){
        string front,back;
        front=a.substr(0,a.find("/"));
        back=a.substr(a.find("/")+1,a.length()-1);
        cout<<RF(front)<<"/"<<RF(back);
    }
    if(flag==4){
        cout<<RF(a.substr(0,a.length()-1))<<"%";
    }
    return 0;
}