//P1050 高精度 + 数论：最后k位循环长度
#include <bits/stdc++.h>
using namespace std;

// ---------- 大整数（非负，base 1e9，小端） ----------
typedef vector<int> VI;
const int BASE = 1000000000;
const int BITS = 30;  // 1e9 < 2^30
void norm(VI& a){ while(!a.empty() && a.back()==0) a.pop_back(); }
int cmp(const VI& a,const VI& b){
    if(a.size()!=b.size()) return a.size()<b.size()?-1:1;
    for(int i=a.size()-1;i>=0;i--) if(a[i]!=b[i]) return a[i]<b[i]?-1:1;
    return 0;
}
VI mulSmall(const VI& a,int x){
    if(x==0||a.empty()) return VI();
    VI r(a.size()+1,0); long long carry=0;
    for(int i=0;i<(int)a.size();i++){ long long cur=(long long)a[i]*x+carry; r[i]=cur%BASE; carry=cur/BASE; }
    r[a.size()]=(int)carry; norm(r); return r;
}
VI addSmall(const VI& a,int x){
    VI r=a; int i=0; long long carry=x;
    while(carry){ if(i==(int)r.size()) r.push_back(0); long long cur=(long long)r[i]+carry; r[i]=cur%BASE; carry=cur/BASE; i++; }
    norm(r); return r;
}
VI subBig(const VI& a,const VI& b){
    VI r=a; long long borrow=0;
    for(int i=0;i<(int)a.size();i++){ long long cur=(long long)a[i]-borrow-(i<(int)b.size()?b[i]:0); if(cur<0){cur+=BASE;borrow=1;}else borrow=0; r[i]=cur; }
    norm(r); return r;
}
VI mulBig(const VI& a,const VI& b){
    if(a.empty()||b.empty()) return VI();
    VI r(a.size()+b.size(),0);
    for(int i=0;i<(int)a.size();i++){ if(a[i]==0) continue; long long carry=0;
        for(int j=0;j<(int)b.size();j++){ long long cur=(long long)r[i+j]+(long long)a[i]*b[j]+carry; r[i+j]=cur%BASE; carry=cur/BASE; }
        int k=i+b.size(); while(carry){ long long cur=(long long)r[k]+carry; r[k]=cur%BASE; carry=cur/BASE; k++; }
    }
    norm(r); return r;
}
VI divSmall(const VI& a,int q){ VI r(a.size(),0); long long rem=0; for(int i=a.size()-1;i>=0;i--){ long long cur=(long long)rem*BASE+a[i]; r[i]=cur/q; rem=cur%q; } norm(r); return r; }
int modSmall(const VI& a,int q){ long long rem=0; for(int i=a.size()-1;i>=0;i--){ rem=(rem*BASE+a[i])%q; } return (int)rem; }
VI modBig(const VI& A,const VI& M){
    if(M.empty()) return A;
    if(cmp(A,M)<0) return A;
    VI rem;
    for(int i=(int)A.size()-1;i>=0;i--)
        for(int b=BITS-1;b>=0;b--){ rem=mulSmall(rem,2); if((A[i]>>b)&1) rem=addSmall(rem,1); if(cmp(rem,M)>=0) rem=subBig(rem,M); }
    norm(rem); return rem;
}
pair<VI,VI> divmodBig(const VI& A,const VI& M){   // 商,余
    if(M.empty()) return {VI(),A};
    if(cmp(A,M)<0) return {VI(),A};
    VI rem,q;
    for(int i=(int)A.size()-1;i>=0;i--)
        for(int b=BITS-1;b>=0;b--){ rem=mulSmall(rem,2);q=mulSmall(q,2); if((A[i]>>b)&1) rem=addSmall(rem,1); if(cmp(rem,M)>=0){ rem=subBig(rem,M); q=addSmall(q,1);} }
    norm(q); norm(rem); return {q,rem};
}
VI powInt(int b,int e){ VI r(1,1); for(int i=0;i<e;i++) r=mulSmall(r,b); return r; }
bool isOne(const VI& a){ return a.size()==1 && a[0]==1; }
VI powmod(VI x, VI e, const VI& m){
    x=modBig(x,m); VI res(1,1);
    while(!e.empty()){ if(e[0]&1) res=modBig(mulBig(res,x),m); e=divSmall(e,2); x=modBig(mulBig(x,x),m); }
    return res;
}
VI gcdBig(VI a,VI b){ while(!b.empty()){ VI t=modBig(a,b); a=b; b=t; } return a; }
VI fromStr(const string& s){
    VI r; for(int i=(int)s.size();i>0;i-=9){ int st=max(0,i-9); int v=0; for(int j=st;j<i;j++) v=v*10+(s[j]-'0'); r.push_back(v); } norm(r); return r;
}
string toStr(const VI& a){
    if(a.empty()) return "0"; string res=to_string(a.back());
    for(int i=a.size()-2;i>=0;i--){ string p=to_string(a[i]); res+=string(9-p.size(),'0')+p; }
    return res;
}

int main(){
    string ns; int k;
    cin >> ns >> k;
    string xs = ((int)ns.size()<=k) ? ns : ns.substr(ns.size()-k);
    VI X = fromStr(xs);
    if(X.empty()){ cout << 1 << "\n"; return 0; }

    int v2=0; VI t=X;
    while(v2<k && modSmall(t,2)==0){ t=divSmall(t,2); v2++; }
    int v5=0; t=X;
    while(v5<k && modSmall(t,5)==0){ t=divSmall(t,5); v5++; }

    if((v2>0 && v2<k) || (v5>0 && v5<k)){ cout << -1 << "\n"; return 0; }

    VI p2(1,1);
    if(v2==0){
        VI m2=powInt(2,k);
        if(k==1) p2=VI(1,1);
        else if(k==2) p2=(modSmall(X,4)==1?VI(1,1):VI(1,2));
        else{ VI o=powInt(2,k-2); while(((o[0]&1)==0) && isOne(powmod(X,divSmall(o,2),m2))) o=divSmall(o,2); p2=o; }
    }

    VI p5(1,1);
    if(v5==0){
        VI m5=powInt(5,k);
        VI o(1,4); for(int i=0;i<k-1;i++) o=mulSmall(o,5);
        for(int q:{2,5}){ while(modSmall(o,q)==0 && isOne(powmod(X,divSmall(o,q),m5))) o=divSmall(o,q); }
        p5=o;
    }

    VI g=gcdBig(p2,p5);
    VI ans=mulBig(divmodBig(p2,g).first, p5);
    cout << toStr(ans) << "\n";
    return 0;
}
