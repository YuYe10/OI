#include <bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.first != b.first) return a.first > b.first;
        else return a.second > b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp > pq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        pair<int, int> s = make_pair(x, i);
        pq.push(s);
    }

    while(k--){
        int t_add,new_x,new_i;
        cin >> t_add;
        new_x = pq.top().first + t_add;
        new_i = pq.top().second;
        pair<int, int> new_s = make_pair(new_x, new_i);
        pq.pop();
        pq.push(new_s);
    }
    cout << pq.top().second << endl;
    /*while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }*/
    return 0;
}