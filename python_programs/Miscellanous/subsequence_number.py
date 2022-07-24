
from itertools import combinations


for _ in range(int(input())):
    n=int(input())
    arr=input().split()

    def subsequece(arr):
        cnt=0
        out=[]
        for l in range(1,len(arr)+1):
            x=list(combinations(arr,l))
            for c in x:
                s="".join(c)
                s=int(s)
                if s%7==0:
                    out.append(s)
                    cnt+=1

        return cnt

    print(subsequece(arr))
    

                    

        
    
        


