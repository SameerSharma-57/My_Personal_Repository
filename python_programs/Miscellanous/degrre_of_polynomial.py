for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    i=n-1
    while l[i]==0 and i>0:
        i-=1
    print(i)