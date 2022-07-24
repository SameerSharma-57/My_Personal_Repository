test_str = input ("The original DNA sequence")

print("The original DNA sequence is :"+ str(test_str))


'''
00 = "A"
01 = "C"
10 = "G"
11 = "T"
'''

test_str = test_str.replace("A","00")
test_str = test_str.replace("C","01")
test_str = test_str.replace("G","10")
test_str = test_str.replace("T","11")

print(test_str)

