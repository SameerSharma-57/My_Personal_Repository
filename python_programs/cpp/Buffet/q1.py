def power(k):
    return 2**k

def solve(arr,n):                     
    out=0
    for i in range(0,32):
        cnt=0
        for j in range(n):
            cnt+=arr[j]%2
            print(n,j)
            arr[j]=arr[j]//2
            if arr[j]==0:
                arr.remove(arr[j])
                n=n-1
        
        if cnt%2==1:
            
            out+=power(i)
    
    return out

for _ in range(int(input())):
    n=int(input())
    inp=list(map(int,input().split()))
    print(solve(inp,n))

'''
13,12,9
'''