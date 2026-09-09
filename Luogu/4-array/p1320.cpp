//p1320 压缩技术（续集版）
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    string s;
    cin>>s;
    int c=s.size();
    int a[c*c];
    int i,cnt,j;
    bool f=0;
    for(j=0;j<c;j++)
    	a[j]=s[j]-'0';
    for(i=1;i<c;i++)
    {
    	cin>>s;	
    	for(j=i*c;j<i*c+c;j++)
    		a[j]=s[j-i*c]-'0';
    }
    cout<<c<<" ";
    i=0;
    while(i<c*c)
    {
    	cnt=0;
    	while(a[i]==f&&i<c*c)
    	{
    		cnt++;
    		i++;
    	}
    	f=!f;
    	cout<<s<<" ";
    }
    return 0;
}