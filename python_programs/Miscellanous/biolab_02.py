def str_to_bin(string):         #converting string into binary
    out=''
    for s in string:
        x=bin(ord(s))           #storing the ASCII values
        x=x.replace('0b','')    #removing prefix'0b' 
        out+=x
    return out

def bin_to_DNA_seq(bin_string):              # encoding the binray into DNA sequence
    out=''
    for i in range(0,len(bin_string),2):     #replacing the binary values with corresponding base
        if bin_string[i:i+2]=='00':
            out+='T'                         #'00'->'T'
        elif bin_string[i:i+2]=='01':
            out+='C'                         #'01'->'C'
        elif bin_string[i:i+2]=='10':
            out+='G'                         #'10'->'G'
        elif bin_string[i:i+2]=='11':       
            out+='A'                         #'11'->'A'
    return out
    
print(bin_to_DNA_seq(str_to_bin('Sameer Sharma is encoding text into the DNA')))    #encoding the string into DNA sequence


        