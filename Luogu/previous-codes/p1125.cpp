//P1125 [NOIP2008 提高组] 笨小猴
#include <bits/stdc++.h>
int isPrime(int t){
    int i;
	int isPrime=1;
    if(t==0 || t==1)return 0;
	for(i=2;i<t;i++){
		if(t%i==0){
			isPrime=0;
			break;
		}
	}
    return isPrime;
}
int main(){
    std::string a;
    int word[27]={0};
    std::cin>>a;
    int i=0;
    while(a[i]!='\0'){
        word[a[i]-'a'+1]++;
        i++;
    }
    int minn;
    std::sort(word+1,word+27);
    for(int j=1;j<=26;j++){
        if(word[j]){
            minn=word[j];break;
        }
    }
    int maxn=word[26];
    int t=maxn-minn;
    if(isPrime(t)){
        std::cout<<"Lucky Word"<<"\n"<<t;
    }else{
        std::cout<<"No Answer"<<"\n"<<0;
    }
    
    return 0;
}