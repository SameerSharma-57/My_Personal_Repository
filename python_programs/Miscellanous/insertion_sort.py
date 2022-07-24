# 1 3 4 5 6 3 2 
def insertion_sort(arr):
    n=len(arr)
    for i in range(n):
        val=arr[i]
        p=i-1
        while p>=0 and arr[p]>val:
            arr[p+1]=arr[p]
            p=p-1
        arr[p+1]=val

arr=[4,3,2,1,4,6,2,13,9,-1,-2,-4]
insertion_sort(arr)
print(arr)