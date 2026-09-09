#include <bits/stdc++.h>
using namespace std;
#define N 400005

bool Majority(int *T, int len, int &num)
{
    int n = rand()%10;
    num = T[n];
    int cnt = 0;
    for(int i=0; i<len; i++)
    {
        if(T[i] == num)
            cnt++;
    }
    return (cnt>len/2);
}

bool MajorityMC(int *T, int len, double e, int &num)
{
    int k = ceil(log(1/e)/log((float)2));
    for(int i=0; i<k; i++)
    {
        if(Majority(T, len, num))
            return true;
    }
    return false;
}

int main()
{
    int num=INT_MAX;
    int n;
    cin>>n;
    float e = 0.001;
    int T[N];
	for(int i=0; i<n; i++)
	{
		cin>>T[i];
	}
    if(MajorityMC(T,n,e,num))
        cout << num << endl;
    return 0;
}
