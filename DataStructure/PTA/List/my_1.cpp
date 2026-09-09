#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct Node{
    int prev;
    int data;
    int next;
}L[N],ans[N];
int main(){

    int head,n,tail;
    scanf("%d%d",&head,&n);
    for(int i = 0; i < n; i++){
        int addr,data,next;
        scanf("%d%d%d",&addr,&data,&next);
    	L[addr].data = ans[addr].data = data;
    	L[addr].next = next;
    	if(next == -1){
            tail = addr;
    	}else{
            L[next].prev = addr;
        }
    }
    
    int temp = tail;
    while(1){
        if(tail == head){
            ans[tail].next = -1;
            break;
        }else{
            ans[tail].next = head;
        }
        tail = L[tail].prev;

        if(tail == head){
            ans[head].next = -1;
            break;
        }else{
            ans[head].next = tail;
        }
        head = L[head].next;
    }
    while(temp != -1){
        printf("%05d %d",temp,ans[temp].data);
        if(ans[temp].next == -1){
            printf(" -1\n");
        }else{
            printf(" %05d\n",ans[temp].next);
        }
        temp = ans[temp].next;
    }
    return 0;
}
