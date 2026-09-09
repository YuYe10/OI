//P1067 [NOIP2009 普及组] 多项式输出
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,i;
    cin>>n;
    for(i=n;i>=0;--i)
	{
        cin>>a;
        if(a)
		{    
            if(i!=n&&a>0) cout<<"+";
            if(abs(a)>1||i==0) cout<<a;
            if(a==-1&&i) cout<<"-";  
            if(i>1) cout<<"x^"<<i;    
            if(i==1) cout<<"x";    
        }
    }
    return 0;
}