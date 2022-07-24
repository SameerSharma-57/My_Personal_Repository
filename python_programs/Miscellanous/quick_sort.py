
def partition(arr,p,r):
    if p<r:
        i=p-1
        m=arr[r]
        for j in range(p,r):
            if arr[j]<m:
                i=i+1
                arr[i],arr[j]=arr[j],arr[i]

        arr[i+1],arr[r]=arr[r],arr[i+1]
        return i+1
    else:
        return -1

def quick_sort(arr,p=0,r=None):
    if r==None:
        r=len(arr)-1
    
    q=partition(arr,p,r)
    # print(q)
    # print("hello")
    if q==-1:
        # print(q)
        return 
    
    # print("HEllo")
    # print(arr)
    quick_sort(arr,p,q-1)
    # print("hello")
    quick_sort(arr,q+1,r)
    

arr=[4,3,2,1,5,4,2,3,6,7,8,1]
quick_sort(arr)
print(arr)
