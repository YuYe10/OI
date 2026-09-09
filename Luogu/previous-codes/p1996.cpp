//P1996 约瑟夫问题
#include <bits/stdc++.h>
using namespace std;
queue <int> q;
int main(){
    int n,n1=1,nout;
    cin>>n>>nout;
    for(int i=1;i<=n;i++)q.push(i);
    while(!q.empty()){
        if(n1==nout){
            cout<<q.front()<<" ";
            q.pop();
            n1=1;
        }else{
            n1++;
            q.push(q.front());
            q.pop();
        }
    }
    return 0;
}