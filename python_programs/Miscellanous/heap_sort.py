def parent(i):
    return i//2

def left(i):
    return 2*i

def right(i):
    return (2*i)+1

def max_heapify(arr,i,heapsize):
    l=left(i)
    r=right(i)
    largest=i

    if r<=heapsize and arr[r-1]>arr[i-1]:
        largest=r
    if l<=heapsize and arr[l-1]>arr[largest-1]:
        largest=l

    if largest!=i:
        arr[i-1],arr[largest-1]=arr[largest-1],arr[i-1]
        max_heapify(arr,largest,heapsize)

arr=[6,5,4,3,2,1,7,8]
#max_heapify(arr,1,3)
#print(arr)

def build_max_heap(arr,heapsize):
    for i in range(heapsize//2,0,-1):
        max_heapify(arr,i,heapsize)


# build_max_heap(arr,len(arr))
# print(arr)

def heap_sort(arr):
    heapsize=len(arr)
    build_max_heap(arr,heapsize)
    for i in range(1,len(arr)+1):
        arr[0],arr[heapsize-1]=arr[heapsize-1],arr[0]
        heapsize=heapsize-1
        max_heapify(arr,1,heapsize)

heap_sort(arr)
print(arr)







