#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

unordered_map<string, int> ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,s;
    cin >> n >> s;
    stack<int> items;
    queue<string> boxes;
    for(int i=0;i<n;i++){
        string a;
        cin >> a;
        boxes.push(a);
    }
    while(!boxes.empty()){
        if(items.empty()){
            while(s > items.size()){
                int x;
                cin >> x;
                items.push(x);
            }
        }
        ans[boxes.front()] = items.top();
        boxes.pop();
        items.pop();
    }
    int k;
    cin >> k;
    while(k--){
        string a;
        cin >> a;
        auto it = ans.find(a);
        if(it != ans.end()){
            cout << it -> second << endl;
        }else{
            cout << "Wrong Number" << endl;
        }
    }
    return 0;
}