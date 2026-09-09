#include <bits/stdc++.h>
#define ll long long
#define inf 0xfff
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        string a[n+1];
        for(int i=1;i<=n;i++){
            int l;
            cin>>l;
            getline(cin,a[i]);
            a[i].erase(remove(a[i].begin(),a[i].end(),' '),a[i].end());
            sort(a[i].begin(),a[i].end());
        }
        
        for(int k=0;k<q;k++){
            int i,j;
            cin>>i>>j;
            string s=a[i]+a[j];
            int ss=s.length();
            sort(s.begin(),s.end());
            if(ss%2==0)cout<<s[ceil(ss/2)-1]<<endl;
            else cout<<s[ceil(ss/2)]<<endl;
        }
    }
    return 0;
}