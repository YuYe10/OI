//P1781 宇宙总统
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;string maxn;
    int maxi;
    cin>>n;

    for(int i=1;i<=n;i++){
        int flag=0;
        string a;
        cin>>a;
        if(a.length() > maxn.length()){
            maxn = a;
            maxi = i;
        }
        else if(a.length() < maxn.length()){
            continue;
        }
        else{
            for(int j=0;j<a.length();j++){
                if(maxn[j] - a[j] < 0){flag=1;break;}
                else if(maxn[j] - a[j] == 0){continue;}
                else break;
            }
            if(flag){
                maxn = a;
                maxi = i;
            }
        }
    }
    cout<<maxi<<endl<<maxn;
    return 0;
}
