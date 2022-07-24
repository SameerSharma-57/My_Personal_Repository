for i in range(int(input())):
    [n,m]=list(map(int,input().split()))
    arr=list(map(int,input().split()))
    total_candy=0
    for j in range(n):
        total_candy+=arr[j]

    print("Case #"+str(i+1)+":",total_candy%m)
