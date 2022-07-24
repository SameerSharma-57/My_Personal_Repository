

for _ in range(int(input())):
    n=int(input())

    l=list(map(int,input().split()))

    def posi(arr,i):
        while arr[i]<0 and i<len(arr):
            i=i+1
        return i
    def negi(arr,i):
        while arr[i]>0 and i>-1:
            i=i-1
        return i


        


    def solve(arr,n):
        i=posi(arr,0)
        j=negi(arr,n-1)
        while i<j:
            arr[i]=(-1)*arr[i]
            arr[j]=(-1)*arr[j]
            i=posi(arr,i+1)
            j=negi(arr,j-1)


    solve(l,n)
    arr=l.copy()
    arr.sort()
    if l==arr:
        print("Yes")
    else:
        print("NO")
            

