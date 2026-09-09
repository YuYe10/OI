#include <bits/stdc++.h>
#define ll long long
#define inf 0xfff
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%4!=0){
        cout<<"No";exit(0);
    }
    string s;
    cin>>s;
    if(count(s.begin(),s.end(),'3')!=0){
        cout<<"No";exit(0);
    }
    if(count(s.begin(),s.end(),'5')!=0){
        cout<<"No";exit(0);
    }
    if(count(s.begin(),s.end(),'6')!=0){
        cout<<"No";exit(0);
    }
    if(count(s.begin(),s.end(),'7')!=0){
        cout<<"No";exit(0);
    }
    if(count(s.begin(),s.end(),'8')!=0){
        cout<<"No";exit(0);
    }
    if(count(s.begin(),s.end(),'9')!=0){
        cout<<"No";exit(0);
    }
    if(count(s.begin(),s.end(),'2')!=count(s.begin(),s.end(),'0') || count(s.begin(),s.end(),'2')!=count(s.begin(),s.end(),'1') || count(s.begin(),s.end(),'2')!=count(s.begin(),s.end(),'4')){
        cout<<"No";exit(0);
    }
    cout<<"Yes";
    return 0;
}