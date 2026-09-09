#include <bits/stdc++.h>

using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    while(n--){
        int x;
        cin >> x;
        pq.push(x);
    }

    while(pq.size() > 1){
        int a = pq.top();pq.pop();
        int b = pq.top();pq.pop();
        ans += (a+b);
        pq.push(a+b);
    }
    cout << ans << endl;
    /*while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }*/
    return 0;
}