#include <bits/stdc++.h>
#define MAX_N 2000005
#define mod 1e9+7
using namespace std;
map<int, int> mp;
int n,t;
struct tree{
    int x,l,r;
    int d;
    int f;
}tree[MAX_N];
int cnt;
int ans[MAX_N];

void dfs(int x, int node){
    if(x < tree[node].x){
        if(!tree[node].l){
            cnt++;
            tree[cnt].x = x;
            tree[node].l = cnt;
            tree[cnt].f = node;
            tree[cnt].d = tree[node].d + 1;
            mp[x] = cnt;
        }else{
            dfs(x, tree[node].l);
        }
    }else{
        if(!tree[node].r){
            cnt++;
            tree[cnt].x = x;
            tree[node].r = cnt;
            tree[cnt].f = node;
            tree[cnt].d = tree[node].d + 1;
            mp[x] = cnt;
        }else{
            dfs(x, tree[node].r);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;

    int x; cin>>x;
    tree[1].x = x;
    tree[1].d = 1;
    mp[x] = 1;
    cnt = 1;

    for (int i = 2 ; i <= n ; i++){
        cin >> x;
        dfs(x, 1);
    }

    cin>>t;
    string s;
    getline(cin, s);
    while(t--){
        getline(cin, s);
        int a = 0,b = 0;

        if(s.find("root") != string::npos){
            sscanf(s.c_str(), "%d is the root", &a);
            if(mp[a] == 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        if(s.find("siblings") != string::npos){
            sscanf(s.c_str(), "%d and %d are siblings", &a, &b);
            a = mp[a];b = mp[b];
            if(!a || !b) cout << "No" << endl;
            else if(tree[a].f != tree[b].f) cout << "No" << endl;
            else if(tree[a].f == tree[b].f) cout << "Yes" << endl;
        }
        if(s.find("parent") != string::npos){
            sscanf(s.c_str(), "%d is the parent of %d", &a, &b);
            a = mp[a];b = mp[b];

            if(!a || !b) cout << "No" << endl;
            else if(tree[b].f != a) cout << "No" << endl;
            else if(tree[b].f == a) cout << "Yes" << endl;
        }
        if(s.find("left") != string::npos){
            sscanf(s.c_str(), "%d is the left child of %d", &a, &b);
            a = mp[a];b = mp[b];

            if(!a||!b) cout << "No" << endl;
            else if(tree[b].l != a) cout << "No" << endl;
            else if(tree[b].l == a) cout << "Yes" << endl;
        }
        if(s.find("right") != string::npos){
            sscanf(s.c_str(), "%d is the right child of %d", &a, &b);
            a = mp[a];b = mp[b];

            if(!a||!b) cout << "No" << endl;
            else if(tree[b].r != a) cout << "No" << endl;
            else if(tree[b].r == a) cout << "Yes" << endl;
        }
        if(s.find("level") != string::npos){
            sscanf(s.c_str(), "%d and %d are on the same level", &a, &b);
            a = mp[a];b = mp[b];

            if(!a||!b) cout << "No" << endl;
            else if(tree[b].d != tree[a].d) cout << "No" << endl;
            else if(tree[b].d == tree[a].d) cout << "Yes" << endl;
        }
    }

    return 0;
}