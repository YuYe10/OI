//P1059 [NOIP2006 普及组] 明明的随机数
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main(){
    int n,m,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    //auto end_unique=unique(a.begin(),a.end());
    //a.erase(end_unique,a.end());
    auto it=a.begin();
    while(it<a.end()-1){
        if(*it==*(it+1)){
            a.erase(it+1);
            continue;
        }
        it++;
    }
    m=a.size();
    cout<<m<<endl;
    for(auto i:a){
        cout<<i<<" ";
    }
    return 0;
}