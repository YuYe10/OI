/* #include <bits/stdc++.h>
using namespace std;

void dfs(int user, const vector<vector<int>>& adj, vector<bool>& visited) {  
    visited[user] = true;  
    for (int neighbor : adj[user]) {  
        if (!visited[neighbor]) {  
            dfs(neighbor, adj, visited);  
        }  
    }  
}  

int main() {  
    int n, m;  
    cin >> n >> m;  

    vector<vector<int>> adj(n); // 创建图的邻接表  
    vector<unordered_set<int>> groups(m + 1); // 用来保存每个群的用户  
    vector<int> user_groups[n];  

    // 输入用户的群信息  
    for (int i = 0; i < n; i++) {  
        int k_i;  
        cin >> k_i;  
        user_groups[i] = vector<int>(k_i);  
        for (int j = 0; j < k_i; j++) {  
            cin >> user_groups[i][j];  
            groups[user_groups[i][j]].insert(i); // 在对应的群中插入用户  
        }  
    }  

    // 构建用户间的连接图  
    for (int i = 1; i <= m; i++) {  
        if (groups[i].size() > 1) {  
            vector<int> users_in_group(groups[i].begin(), groups[i].end());  
            for (int j = 0; j < users_in_group.size(); j++) {  
                for (int k = j + 1; k < users_in_group.size(); k++) {  
                    adj[users_in_group[j]].push_back(users_in_group[k]);  
                    adj[users_in_group[k]].push_back(users_in_group[j]);  
                }  
            }  
        }  
    }  

    // 找出连通分量  
    vector<bool> visited(n, false);  
    int component_count = 0;  

    for (int i = 0; i < n; i++) {  
        if (!visited[i]) {  
            dfs(i, adj, visited);  
            component_count++; // 每次dfs对应一个新的连通块  
        }  
    }  

    // 计算需要的群组数量  
    cout << component_count - 1 << endl; // 连接k个连通块需要k-1个边  
    return 0;  
}   */
#include<bits/stdc++.h>
using namespace std;
 
int fa[100010],ans,cnt;
vector<int>a[100010];
int find(int x){
    if(x == fa[x]){
        return x;
    }else{
        return fa[x] = find(fa[x]);
    }
}

void Union(int a, int b){
    int u = fa[a];
    int v = fa[b];
    if(u != v) fa[v] = u;
}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;

    for(int i=1; i<=n; ++i){
        fa[i] = i;
    }

    for(int i=1; i<=n; ++i){
        int k;
        cin >> k;
        if(k == 0)
            cnt++;
        while(k--){
            int x;
            cin >> x;
            a[x].push_back(i);
        }
    }

    for(int i=1; i<=n; ++i){
        for(int j=1; j<a[i].size(); ++j){
            Union(a[i][0], a[i][j]);
        }
    }

    for(int i=1; i<=n; ++i) if(find(i) == i) ans++;
    if(cnt == n) cout << cnt;
    else cout << ans - 1;

	return 0;
}