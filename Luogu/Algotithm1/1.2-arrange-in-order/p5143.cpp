#include <bits/stdc++.h>
using namespace std;
struct Map{
    int x;
    int y;
    int z;
}M[50005];
bool cmp(Map M1,Map M2){
    if(M1.z>M2.z) return 0;
    return 1;
}
int main(){
	int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>M[i].x>>M[i].y>>M[i].z;
    }
    sort(M,M+n,cmp);
    double dis=0.0;
    for(int i=0;i<n-1;i++){
        dis+=sqrt(pow(fabs(M[i+1].x-M[i].x),2)+pow(fabs(M[i+1].y-M[i].y),2)+pow(fabs(M[i+1].z-M[i].z),2));
    }
    printf("%.3lf",dis);
	return 0;
}