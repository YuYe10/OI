import subprocess, random
def period(n,k):
    m=10**k; T=6000
    seq=[pow(n,a,m) for a in range(1,T+1)]
    for L in range(1,3000):
        ok=True
        for a in range(T-L):
            if seq[a]!=seq[a+L]: ok=False;break
        if ok: return L
    return -1
def sol(n,k):
    return int(subprocess.run(['./p1050_test'],input=f"{n} {k}\n".encode(),capture_output=True).stdout.decode().strip())
bad=0; cases=[]
for n in [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,31,32,33,101,111,201]:
    cases.append((n,4))
for _ in range(15): cases.append((random.randint(1,500),4))
for (n,k) in cases:
    a=period(n,k); b=sol(n,k)
    if a!=b: bad+=1; print("MISMATCH n=%d k=%d brute=%d sol=%d"%(n,k,a,b))
print("k=4 done bad=",bad,"of",len(cases))
