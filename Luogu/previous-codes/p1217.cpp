//P1217 回文质数 Prime Palindromes
#include <bits/stdc++.h>
using namespace std;
int isPalindrome(const int a);
int isPrime(const int a);
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int arr[1000];
    int j=0;
    for (int x=a;x<=9989889;x++)
	    {	
		if(isPrime(x)){
		arr[j]=x;
        if(isPalindrome(x)){
            printf("%d\n",arr[j]);
        }else{
            continue;
        }
        j++;
        }else{
            continue;
        }
	}
    

    return 0;
}

int isPalindrome(const int a){
    int s,y=0;
    s=a;
	while(s>0){
		y=y*10+s%10;
		s=s/10;
	}
    if(y==a){
        return 1;
    }else{
        return 0;
    }
}

int isPrime(const int a){
        if(a<=3 && a>1){
            return 1;
        }
        if((a%6!=1)&&(a%6!=5)){
            return 0;
        }
        for(int i=5;i<sqrt(a);i+=6){
            if(a%i==0 || a%(i+2)==0){
                return 0;
            }
        }
        return 1;
}