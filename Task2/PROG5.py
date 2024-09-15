def binary(num):
    if num >= 1:
        binary(num // 2)
    print(num % 2, end='')
import os
os.system("cls")    
num=int(input("Enter a number: "))
binary(num)