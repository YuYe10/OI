//P1321 单词覆盖还原
#include <bits/stdc++.h>
using namespace std;
int main(){
    int boy=0,girl=0;
    string a;
    cin>>a;
    for(int i=0;i<=a.length();i++)
      if(a[i]=='b'||a[i+1]=='o'||a[i+2]=='y')boy++;
    for(int i=0;i<=a.length();i++)
      if(a[i]=='g'||a[i+1]=='i'||a[i+2]=='r'||a[i+3]=='l')girl++;
    cout<<boy<<endl<<girl;               
    return 0;
}