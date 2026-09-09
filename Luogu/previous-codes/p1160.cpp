//P1160 队列安排
#include <bits/stdc++.h>
using namespace std;
list <int> a;
using it = list <int>::iterator ;
it p[100005];
bool judge[100005];
int main(){
    int n;
    cin>>n;
    a.push_front(1);
    p[1]=a.begin();
    for(int i=2;i<=n;i++){
        int index,sign;
        cin>>index>>sign;
        if(sign==0){
            p[i]=a.insert(p[index],i);
        }else{
            auto itnext=next(p[index]);
            p[i]=a.insert(itnext,i);
        }
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        if(!judge[t]){
            a.erase(p[t]);
        }
        judge[t]=true;
    }
    bool first = true;
    for (int x: a){
        if (!first)
            putchar(' ');
        first = false;
        printf("%d", x);
    }
    putchar('\n');
    return 0;
}