//P5730 【深基5.例10】显示屏
#include <bits/stdc++.h>
using namespace std;
char a[10][5][4]=
    {
    "XXX",//0
	"X.X",
	"X.X",
	"X.X",
	"XXX",
	"..X",//1
	"..X",
	"..X",
	"..X",
	"..X",
	"XXX",//2
	"..X",
	"XXX",
	"X..",
	"XXX",
	"XXX",//3
	"..X",
	"XXX",
	"..X",
	"XXX",
	"X.X",//4
	"X.X",
	"XXX",
	"..X",
	"..X",
	"XXX",//5
	"X..",
	"XXX",
	"..X",
	"XXX",
	"XXX",//6
	"X..",
	"XXX",
	"X.X",
	"XXX",
	"XXX",//7
	"..X",
	"..X",
	"..X",
	"..X",
	"XXX",//8
	"X.X",
	"XXX",
	"X.X",
	"XXX",
	"XXX",//9
	"X.X",
	"XXX",
	"..X",
	"XXX"
    },ans[10][1000];
int main()
{
    int n;
    scanf("%d",&n);
    int num,position=0;char x;
    for(int k=0;k<n;k++){
		//x=getchar();
		//num=x-'0';
        scanf("%1d",&num);
        for(int i=0;i<5;i++){
            for(int j=0;j<3;j++){
                ans[i][position+j]=a[num][i][j];
            }
        }
        for(int i=0;i<5;i++){
            ans[i][position+3]='.';
        }position+=4;
    }
    for(int i=0;i<5;i++){
            for(int j=0;j<position-1;j++){
                printf("%c",ans[i][j]);
            }printf("\n");
    }
    return 0;
}