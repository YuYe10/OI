#include <iostream>
using namespace std;
class Student
 {public:
   
    Student(int a,float b):num(a),score(b){};
//利用参数初始化表进行数据初始化
    void display();
  private:
    int num;
    float score;
 };

void Student::display()
 {cout<<num<<" "<<score<<endl;}
 
int main()
{
  Student stud[5]={
  Student(101,78.5),Student(102,85.5),Student(103,98.5),
  Student(104,100.0),Student(105,95.5)}; //定义对象数组
 
Student *p = stud;
//定义对象指针指向对象数组
 for(int i=0;i<3;p+=2,i++)//显示第1、3、5名学生信息
  p->display();
 return 0;
 }

