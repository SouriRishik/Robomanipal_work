import os
os.system("cls")
import math
print("Calculating Distance between two points (x1,y1) and (x2,y2) using the formula: _/(x2-x1)^2+(y2-y1)^2")
x1=float(input("Enter the x1 cordinate of first point: "))
y1=float(input("Enter the y1 cordinate of first point: "))
x2=float(input("Enter the x2 cordinate of second point: "))
y2=float(input("Enter the y2 cordinate of second point: "))
distance = math.sqrt(pow((x2 - x1),2) + pow((y2 - y1),2))

print("The distance between the two points is:", round(distance,2))