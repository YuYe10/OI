//P5742 【深基7.例11】评等级
#include <bits/stdc++.h>
using namespace std;
struct Student{
    string id;
    int s1;
    int s2;
    double s;
};
int main(){
    int n;
    cin>>n;
    Student stu[n];
    for(int i=0;i<n;i++){
        cin>>stu[i].id>>stu[i].s1>>stu[i].s2;
        stu[i].s=stu[i].s1*0.70+stu[i].s2*0.30;
        if(stu[i].s1+stu[i].s2>140 && stu[i].s1*7+stu[i].s2*3>=800){
            cout<<"Excellent"<<endl;
        }else{
            cout<<"Not excellent"<<endl;
        }
    }

    return 0;
}