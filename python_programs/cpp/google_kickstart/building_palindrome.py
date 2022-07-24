


def solve(string):
    count={}
    for i in string:
        if i in count:
            count[i]+=1
        else:
            count[i]=1
    cnt=0
    for x in count:
        if count[x]%2==1:
            cnt+=1
        if cnt>1:
            break

    
    n=len(string)
    if n%2==0 and cnt==0:
        return 1
    elif n%2==1 and cnt==1:
        return 1
    return 0


for i in range(int(input())):
    [n,q]=list(map(int,input().split()))
    string=input()
    cnt=0
    for j in range(q):
        [l,r]=list(map(int,input().split()))
        cnt+=solve(string[(l-1):r])
        
    print("Case #"+str(i+1)+":",cnt)
