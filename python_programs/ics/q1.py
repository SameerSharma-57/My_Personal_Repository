def count(l,ch):
    cnt=0
    for x in l:
        if x==ch:
            cnt+=1
    return cnt

def countPairs(l,li):
    cnt=0
    for i in range(0,len(l)-1):
        if l[i:i+2]==li:
            cnt+=1
    return cnt
class TextStatictics():

    
    
    def generateWS(self,para):
        d={}
        l=para.split()
       
        for x in l:
            d[x]=count(l,x)
        return d

    def generateWpairS(self,para):
        out={}
        l=para.split()
        for i in range(0,len(l)-1):
            val=[l[i],l[i+1]]
            out[tuple(val)]=countPairs(l,val)
        return out
Ts=TextStatictics()           
s='only a life lived for other is a life worthwhile'
d=Ts.generateWS(s)
d1=Ts.generateWpairS(s)
print(d)
print(d1)