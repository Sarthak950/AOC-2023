history=open('./test.txt').readlines()

from math import comb
def Lagrange(nums):
    n=len(nums)
    res=0
    for i,x in enumerate(nums):
        res+=x*comb(n,i+1)*(-1)**(i)
    return res

res = 0
for line in history:
    nums=list(map(int,line.strip().split()))
    res+=Lagrange(nums)
print(res)
