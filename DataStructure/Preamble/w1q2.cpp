#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=0;
	cin>>n;
	
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	int result=a[0];//假设第一个元素为主元素majo
	int cnt=1;//cnt从1开始是因为无论majo是谁都至少有一个 
	
	for(int j=1;j<n;j++)//开始遍历数组与假设的X作对比 
	{
		if(a[j]==result){
			cnt++;//如果与假设的majo相同cnt++ 
		}else if(cnt==1){
			result=a[j];//与majo不同但cnt=1，说明假设错误，更新majo，重置cnt 
			cnt=1;
		}else{
			cnt--;//与majo不同且cnt！=1，cnt-- 
		}
	}
	cnt=0;
	for(int k=0;k<n;k++)//遍历数组，检查找出来的majo在数组中是否超过（n/2） 
	{
		if(a[k]==result)
		cnt++;
	}
	if(cnt>(n/2)){
		cout<<result<<endl;
	}else cout<<"0"<<endl;
	
	return 0;
}