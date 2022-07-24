def tuppleList(arr):
    out1=[]
    out2=[]
    for i in range(len(arr)):
        for j in range(len(arr[0])):
            out1.append((i,j))
            out2.append(arr[i][j])
    return [out1,out2]


def find_ind(li,el):
    
    for i in range(len(li)):
        if li[i]==el:
            return i

def OrderedMatrix(arr):
    out=arr.copy()
    res=tuppleList(arr)
    flat_list=res[1]
    tupple_list=res[0]

    
    for i in range(len(flat_list)):
        val=flat_list[i]
        val2=tupple_list[i]
        p=i-1
        while p>=0 and flat_list[p]>val:
            flat_list[p+1]=flat_list[p]
            tupple_list[p+1]=tupple_list[p]


            p=p-1
        flat_list[p+1]=val
        tupple_list[p+1]=val2
    for i in range(len(out)):
        for j in range(len(out[0])):
            out[i][j]=find_ind(tupple_list,(i,j))+1
    return out

print(OrderedMatrix([[11,49,85,99],[4,84,36,29],[45,56,85,22],[98,91,88,77]]))
    


    
