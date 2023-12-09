history=open('./test.txt').readlines()

from math import comb
def Lagrange(nums):
    n=len(nums)
    res=0
    for i,x in enumerate(nums):
        res+=x*comb(n,i)*(-1)**(n-1-i)
    return res
res = 0
for line in history:
    nums=list(map(int,line.strip().split()))
    a=Lagrange(nums)
    print("current sum: ", a)
    res+=a
print(res)
