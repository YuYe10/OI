//P1957 口算练习题
#include <bits/stdc++.h>
int main(){
    int i,x,y;
    char s[20],ans[100],c;
    std::cin>>i;
    while(i--){
        scanf("%s",&s);
        if(isalpha(s[0])){
            c=s[0];
            scanf("%d%d",&x,&y);
        }else{
            x=atoi(s);
            scanf("%d",&y);
        }
        if(c=='a'){
            sprintf(ans,"%d+%d=%d",x,y,x+y);
        }
        if(c=='b'){
            sprintf(ans,"%d-%d=%d",x,y,x-y);
        }
        if(c=='c'){
            sprintf(ans,"%d*%d=%d",x,y,x*y);
        }
        printf("%s\n%d\n",ans,strlen(ans));
    }
    return 0;
}