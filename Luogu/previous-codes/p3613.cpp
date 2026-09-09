//P3613 【深基15.例2】寄包柜
#include <bits/stdc++.h>
using namespace std;
map<int,map<int, int> > a;
int main(){
    int n,q;
    cin>>n>>q;
    while(q--){
        int op;
        cin>>op;
        int x,y;
        cin>>x>>y;
        if(op==1){
           
            int s;
            cin>>s;
            a[x][y]=s;
        }else{
            printf("%d\n",a[x][y]);
        }
    }
    return 0;
}