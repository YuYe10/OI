//P1328 [NOIP2014 提高组] 生活大爆炸版石头剪刀布
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int kombat[5][5]{
    {0,0,1,1,0},
    {1,0,0,1,0},
    {0,1,0,0,1},
    {0,0,1,0,1},
    {1,1,0,0,0},
};
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> va;
    vector<int> vb;
    int scorea=0,scoreb=0;
    for(int i=0;i<a;i++){
        int x;
        cin>>x;
        va.push_back(x);
    }
    for(int i=0;i<b;i++){
        int x;
        cin>>x;
        vb.push_back(x);
    }
    for(int i=a;i<n;i++){
        va.push_back(va[i%a]);
    }
    for(int i=b;i<n;i++){
        vb.push_back(vb[i%b]);
    }
    for(int i=0;i<n;i++){
        scorea+=kombat[va[i]][vb[i]];
        scoreb+=kombat[vb[i]][va[i]];
    }
    cout<<scorea<<" "<<scoreb;
    return 0;
}