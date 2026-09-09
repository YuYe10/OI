//P1104 生日
#include <bits/stdc++.h>
using namespace std;
struct student{
    string a;
    int y;
    int m;
    int d;
    int id;
}s[105];
bool cmp(student s1,student s2){
    if(s1.y!=s2.y){
        return s1.y<s2.y;
    }else{
        if(s1.m!=s2.m){
            return s1.m<s2.m;
        }else{
            if(s1.d!=s2.d){
                return s1.d<s2.d;
            }else{
                return s1.id>s2.id;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i].a>>s[i].y>>s[i].m>>s[i].d;
        s[i].id=i;
    }
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++){
        cout<<s[i].a<<endl;
    }
    return 0;
}