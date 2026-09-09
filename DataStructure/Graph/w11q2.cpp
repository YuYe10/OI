#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll inf = 1e18+1;
const int N = 500005;

int w[N];

ll mt[N], ans;

struct edge{
    int next;
    int to;
    int w;
}e[2*N];

int cnt = 0;
vector<int> head(N, -1);

void add_edge(int u, int v, int w){
    cnt++;
    e[cnt].to = v;
    e[cnt].w = w;
    e[cnt].next = head[u];

    head[u] = cnt;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1; i<=n; ++i){
        scanf("%d", &w[i]);
    }
    for(int i=0; i<m; ++i){
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        add_edge(u, v, t+w[u]);
        add_edge(v, u, t+w[v]);
    }

    for(int i=2; i<=n; ++i) mt[i] = inf;

    queue<int> q;

    q.push(1);

    while(!q.empty()){
        int _q = q.front();q.pop();
        for(int i = head[_q]; i!= -1; i = e[i].next){
            int des = e[i].to;
            int t = e[i].w;

            if(mt[_q] + t < mt[des]){
                mt[des] = mt[_q] + t;
                if(des == n){
                    ans = mt[des];
                }else{
                    q.push(des);
                }
            }
        }
    }

    cout << ans;
    return 0;
}