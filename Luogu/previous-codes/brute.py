import subprocess
def period(n,k):
    m=10**k
    T=1500
    seq=[pow(n,a,m) for a in range(1,T+1)]
    for L in range(1,700):
        ok=True
        for a in range(T-L):
            if seq[a]!=seq[a+L]: ok=False;break
        if ok: return L
    return -1
def sol(n,k):
    out=subprocess.run(['./p1050_test'],input=f"{n} {k}\n".encode(),capture_output=True).stdout.decode().strip()
    return int(out)
bad=0
cases=[]
for k in range(1,4):
    for n in range(1,41): cases.append((n,k))
import random
for _ in range(40): cases.append((random.randint(1,300), random.randint(1,3)))
for (n,k) in cases:
    a=period(n,k); b=sol(n,k)
    if a!=b:
        bad+=1
        print("MISMATCH n=%d k=%d  brute=%d sol=%d"%(n,k,a,b))
        if bad>10: break
print("done, bad=",bad,"of",len(cases))
