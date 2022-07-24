l=list(map(int,input().split()))

cnt=0
for k in l:
    if k>=10:
        cnt+=1
    
print(cnt)
# 12 15 8 10