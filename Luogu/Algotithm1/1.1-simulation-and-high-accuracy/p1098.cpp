//P1098 [NOIP2007 提高组] 字符串的展开
#include <bits/stdc++.h>
#define ll long long
#define inf 0xfff
#define endl "\n"
using namespace std;
int main(){
    int p1,p2,p3;
    string s;
    cin>>p1>>p2>>p3;
    cin>>s;
    for(register int i=1;i<s.length()-1;i++){
        if(s[i]=='-' && ((islower(s[i-1])&&islower(s[i+1])&&s[i-1]<s[i+1]) || (isdigit(s[i-1])&&isdigit(s[i+1])&&s[i-1]<s[i+1]))){
            if(p1==1){
                s.erase(i,1);
                string ss="";
                for (register int j = s[i - 1] + 1; j < s[i]; j++)
                    for (register int k = 0; k < p2; k++)
                        ss.push_back(j);


                if(p3==2)reverse(ss.begin(),ss.end());
                s.insert(i,ss);
            }else if(p1==2){
                s.erase(i,1);
                string ss="";
                for(register int j=s[i-1]+1;j<s[i];j++){
                    for(register int k=0;k<p2;k++){
                        ss.push_back(toupper(j));
                    }
                }
                if(p3==2)reverse(ss.begin(),ss.end());
                s.insert(i,ss);
            }else if(p1==3){
                s.erase(i,1);
                string ss="";
                for(register int j=s[i-1]+1;j<s[i];j++){
                    for(register int k=0;k<p2;k++){
                        ss.push_back('*');
                    }
                }
                if(p3==2)reverse(ss.begin(),ss.end());
                s.insert(i,ss);
            }
        }
    }
    cout<<s<<endl;
    return 0;
}