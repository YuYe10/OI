//P1449 后缀表达式
#include <bits/stdc++.h>
using namespace std;
stack<int > n;
int main(){
    long long x;
    char op='0';
    while(op!='@'){
        cin>>op;
        if(op>='0' && op<='9'){
            x=op-'0';
            while(1){
                cin>>op;
                if(op!='.'){
                    x=x*10+op-'0';
                }else{
                    break;
                }
            }
            n.push(x);
        }
        else{
            int t;
            switch(op){
                case '.':break;
                case '*':t=n.top();n.pop();n.top()*=t;break;
                case '-':t=n.top();n.pop();n.top()-=t;break;
                case '+':t=n.top();n.pop();n.top()+=t;break;
                case '/':t=n.top();n.pop();n.top()/=t;break;
            }
        }
    }
    int sum=n.top();
    cout<<sum;
    return 0;
}