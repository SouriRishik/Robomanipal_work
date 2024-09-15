def compress_string(string):
    i=0
    compressed=[]
    n=len(string)
    while i < n:
        count = 1
        while i + 1 < n and string[i] == string[i + 1]:
            count+= 1
            i+= 1
        if count > 1:
            compressed.append("("+str(count)+","+(string[i])+")")
        else:
            compressed.append(string[i])
        i+= 1

    return ' '.join(compressed)
import os
os.system("cls")
original_string = input("Enter a string: ")
compressed_string = compress_string(original_string)
print(compressed_string)