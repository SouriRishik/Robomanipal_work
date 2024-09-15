import os
os.system("cls")
n = int(input("Enter an integral number: "))
result={}
if n<1:
    print("Please enter a number greater than 0")
else:
    for i in range(1, n+1):
        result[i] = i*i
    print(result)