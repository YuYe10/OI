//P2911 [USACO08OCT] Bovine Bones G
#include <bits/stdc++.h>
using namespace std;
int main(){
    int s1,s2,s3;
    int a[200005]={0};int maxx=0;
    cin>>s1>>s2>>s3;
    for(int i=1;i<=s1;i++){
        for(int j=1;j<=s2;j++){
            for(int k=1;k<=s3;k++){
                a[i+j+k]++;
                maxx=max(maxx,i+j+k);
            }
        }
    }
    int max=0,maxi=0;
    for(int i=1;i<=maxx;i++){
        if(a[i]>max){
            max=a[i];
            maxi=i;
        }
    }
    cout<<maxi;
    return 0;
}