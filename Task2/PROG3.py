import os
os.system("cls")
n=int(input("Enter the size of the list: "))
print("Enter the list of numbers: ")
num=[]
for i in range(0,n):
    ele=input()
    num.append(ele)
num.sort()
print(num)
s_large=num[n-2]
print("The second largest number in the list is: ",s_large)