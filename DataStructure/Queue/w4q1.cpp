#include<iostream>
#include<queue>
using namespace std;
const int N = 100000100;
int num[N],ans,lazy_tag[N],num_triple;
queue<int> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        num[x]++;
        q.push(x);
        if(num[x] == 3){
            ans++;
            lazy_tag[x] += 3;
            num_triple += 3;
            num[x] -= 3;
        }
        if(q.size() > m + num_triple){
            while(lazy_tag[q.front()] > 0){
                lazy_tag[q.front()]--;
                q.pop();
                num_triple--;
            }
            num[q.front()]--;
            q.pop();
        }
    }
    cout << ans;
    return 0;
}
