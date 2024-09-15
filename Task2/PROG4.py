import os
os.system("cls")
num=[]
for i in range(2000,3201):
  if(i%7==0 and i%5!=0):
    ele=i
    num.append(ele)
print(*num,sep=", ")