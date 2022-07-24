for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))

    def solve(arr,l,r):
        c=r-l+1
        if c in arr[l:r+1]:
            return 1
        else: 
            return 0
    def solve_arr(arr):
        n=len(arr)
        cnt=0
        for i in range(n):
            cnt+=solve(arr,0,i)
            
        return cnt

    out=0
    for i in range(n):
        out+=solve_arr(arr[i:n])

    print(out)
        


    