
from math import log2




for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    arr.sort()
    cnt=0
    while arr[n-1]>0:
        x=int(log2(arr[n-1]))
        
        i=n-1
        while arr[i]>=2**x:
            arr[i]=arr[i]-(2**x)
            i=i-1
        arr.sort()
        
        cnt+=1
        
    print(cnt)
