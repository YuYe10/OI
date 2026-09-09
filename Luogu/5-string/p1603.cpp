//P1603 斯诺登的密码
#include <bits/stdc++.h>
using namespace std;
char a[100][100]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","a","both","another","first","second","third"};
int  b[100]={0,1,4,9,16,25,36,49,64,81,0,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};
char s[100]={};
int main(){
    int ans[20]={0};int it=0;int flag=0;
    for(int i=0;i<6;i++){
        scanf("%s",&s);
        for(int j=0;j<=25;j++)
        if(!strcmp(s,a[j])){
            ans[it++]=b[j];
            flag=1;
            break;
        }
        
    }
    if(!flag){printf("0");return 0;}
    int f=1;
    sort(ans,ans+it);
    for(int i=0;i<it;i++){
        if(ans[i]==0 && f)continue;
        if(ans[i]<10 && f){printf("%.1d",ans[i]);f=0;}
        else {printf("%.2d",ans[i]);}
    }
    return 0;
}