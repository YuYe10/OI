#include <bits/stdc++.h>
using namespace std;
struct stu
{
    int num;
    int ch,math,en; 
    int sum;
}s[310];
bool cmp(stu a,stu b)
{
    if(a.sum>b.sum) return 1;
    else if(a.sum<b.sum) return 0;
    else
    {
        if(a.ch>b.ch) return 1;
        else if(a.ch<b.ch) return 0;
        else
        {
            if(a.num>b.num) return 0;
            else return 1;
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        s[i].num=i;
        cin>>s[i].ch>>s[i].math>>s[i].en;
        s[i].sum=s[i].ch+s[i].math+s[i].en;
    }
    sort(s+1,s+n+1,cmp);
    for(int i=1;i<=5;i++){
        cout<<s[i].num<<" "<<s[i].sum<<endl;
    }
    return 0;
}