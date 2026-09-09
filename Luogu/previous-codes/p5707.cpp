#include <bits/stdc++.h>
int main()
{
    int s,v;
    int h=7;
    int m=50;
    int m1;
    scanf("%d %d",&s,&v);
    if(s/v==0){
        printf("%02d:%02d",h,m-1);
    }else{
        if(s%v!=0)m1=(s/v)+1;
        else m1=s/v;
        if(m1>=60*7+50){
            m1-=60*7+50;
            if(m1%60!=0){m=(60-m1%60);
            h=24;
            h--;
            h-=m1/60;}
            else{m=0;
                h=24;
                h-=m1/60;
            }
            printf("%02d:%02d",h,m);
        }else{
            h-=m1/60;
            if(m1%60>=50){
                h-=1;
                m+=60;
                m-=m1%60;
                printf("%02d:%02d",h,m);
            }else{
                m-=m1%60;
                printf("%02d:%02d",h,m);
            }
        }
    }
    return 0;
}