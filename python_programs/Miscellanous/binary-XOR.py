for _ in range(int(input())):
    n=int(input())
    s=input()
    
    
    
    cnt=0
    r=(n)//2
    for i in range(r):
            
        if s[i]!=s[n-i-1]:
                
            cnt+=1

    print((cnt+1)//2)