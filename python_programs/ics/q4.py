def processString(string):
    
    d={'(':')','[':']','{':'}'}
    
    ind1=0
    ind2=len(string)-1
    
    for i in range(len(string)):
        if string[i] in d.keys():
            ind1=i
            break
    
    if ind1==0:
        return string
    
    for j in range(ind1,len(string)):
        if string[j]==d[string[ind1]]:
            ind2=j
            break
    
    out=string[:ind1]+string[ind2+1:]
    
    
    
    return processString(out)
print(processString('only a{ lif}e lived( for) ot(her))s is life {worthwhile.}'))


