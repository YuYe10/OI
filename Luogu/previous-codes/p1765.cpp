//P1765 手机
#include <bits/stdc++.h>
using namespace std;
int main(){
    string a;
    getline(cin,a);
    char *p=&a[0];int cnt=0;
    while(*p!='\0'){
        if(*p==' ')cnt++;
        if(*p=='a' ||*p=='d' ||*p=='g' ||*p=='j' ||*p=='m' ||*p=='p' ||*p=='t' ||*p=='w')cnt++;
        if(*p=='b' ||*p=='e' ||*p=='h' ||*p=='k' ||*p=='n' ||*p=='q' ||*p=='u' ||*p=='x')cnt+=2;
        if(*p=='c' ||*p=='f' ||*p=='i' ||*p=='l' ||*p=='o' ||*p=='r' ||*p=='v' ||*p=='y')cnt+=3;
        if(*p=='s' || *p=='z')cnt+=4;
        p++;
    }
    cout<<cnt;
    return 0;
}