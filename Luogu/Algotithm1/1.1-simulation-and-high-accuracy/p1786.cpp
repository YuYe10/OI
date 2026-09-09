//P1786 帮贡排序
#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> office_rank;
struct member{
    string office;
    string name;
    int contribution;
    int level; 
    int id;
};
bool cmp(member m1,member m2){
    if(m1.contribution!=m2.contribution)
        return m1.contribution>m2.contribution;
    else
        return m1.id<m2.id;

}
bool cmp1(member m1,member m2){
    if(office_rank[m1.office]==office_rank[m2.office]){
        if(m1.level==m2.level){return m1.id<m2.id;}
        return m1.level>m2.level;
    }
    return office_rank[m1.office]>office_rank[m2.office];
}
int main(){
    int n;
    cin>>n;
    member m[n+1];
    for(int i=1;i<=n;i++){
        m[i].id=i;
        cin>>m[i].name>>m[i].office>>m[i].contribution>>m[i].level;
    }
    office_rank["BangZhu"]=7;
    office_rank["FuBangZhu"]=6;
    office_rank["HuFa"]=5;
    office_rank["ZhangLao"]=4;
    office_rank["TangZhu"]=3;
    office_rank["JingYing"]=2;
    office_rank["BangZhong"]=1;
    sort(m+4,m+n+1,cmp);
    for (int i=1;i<=n;i++){
		if (i==1) m[i].office="BangZhu";
		else if (i==2||i==3) m[i].office="FuBangZhu";
		else if (i==4||i==5) m[i].office="HuFa";
		else if (i>=6&&i<=9) m[i].office="ZhangLao";
		else if (i>=10&&i<=16) m[i].office="TangZhu";
		else if (i>=17&&i<=41) m[i].office="JingYing";
		else m[i].office="BangZhong";
	}
    sort(m+4,m+n+1,cmp1);
    for(int i=1;i<=n;i++){
        cout<<m[i].name<<' '<<m[i].office<<' '<<m[i].level<<endl;
    }
    return 0;
}