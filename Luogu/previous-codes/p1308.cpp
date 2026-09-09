//P1308 [NOIP2011 普及组] 统计单词数
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    string w;
    getline(cin,w);
    getline(cin,s);
    transform(s.begin(),s.end(),s.begin(),::toupper);
    transform(w.begin(),w.end(),w.begin(),::toupper);
     //因为连起来的不算，所以要在前后加几个空格，
     //一定要是同样多的，同量减同量，等于同量
    w=' '+w+' ';
    s=' '+s+' ';
    int cnt=0;int pos=s.find(w);
    if(s.find(w)==string::npos){
        cout<<-1<<endl;
    }else{
        int b=s.find(w);
        while(b!=string::npos){
            cnt++;
            b=s.find(w,b+1);
        }
        printf("%d %d",cnt,pos);
    }
    
    
    return 0;
}