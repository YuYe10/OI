//P1068 [NOIP2009 普及组] 分数线划定
#include <bits/stdc++.h>
using namespace std;
struct zyz{
    string num;
    int score;

}a[5005];
bool cmp(zyz a,zyz b){
    if(a.score>b.score) return 1;
    if(a.score==b.score && a.num<b.num) return 1;
    return 0;
}
int main(){
    int n,m;
    int pass;int cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].score;
    }
    sort(a+1,a+n+1,cmp);
    pass = a[3*m/2].score;
    for(int i=1;i<=n;i++){
        if(a[i].score>=pass)cnt++;
    }
    cout<<pass<<' '<<cnt<<endl;
    for(int i=1;i<=cnt;i++){
        cout<<a[i].num<<' '<<a[i].score<<endl;
    }
    return 0;
}