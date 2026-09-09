#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
struct tree{
    int l;
    int r;
};
tree t[N];
void pre(int x){
    cout << x << ' ';
    if(t[x].l) pre(t[x].l);
    if(t[x].r) pre(t[x].r);
}

void post(int x){
    if(t[x].l) post(t[x].l);
    if(t[x].r) post(t[x].r);
    cout << x << ' ';
}
int fa[N], in[N], v[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int n;
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> fa[i];
    }
    for(int i=1; i<=n; ++i){
        cin >> in[i];
    }

    for(int i=1; i<=n; ++i){
        if(v[fa[in[i]]]){
            t[fa[in[i]]].r = in[i];
        }else{
            t[fa[in[i]]].l = in[i];
        }
        v[fa[in[i]]] = 1;
    }

    pre(t[0].l);
    cout << endl;
    post(t[0].l);
	return 0;
}