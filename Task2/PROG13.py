inventory = {}

def add_item(item_name, quantity):
    if item_name in inventory:
        inventory[item_name]+= quantity
        print("UPDATED Item", (item_name))
    else:
        inventory[item_name] = quantity
        print("ADDED Item", (item_name))

def delete_item(item_name, quantity):
    if item_name not in inventory:
        print("Item",(item_name)," does not exist")
    else:
        if inventory[item_name]<quantity:
            print("Item",(item_name),"could not be DELETED")
        else:
            inventory[item_name]-= quantity
            print("DELETED Item",(item_name))

import os
os.system("cls")
N = int(input("Enter the number of initial items in the lab: "))
print("Enter the initial inventory (item_name quantity):")
for _ in range(N):
    item_name, quantity = input().split()
    quantity = int(quantity)
    inventory[item_name] = quantity

n = int(input("Enter the number of operations: "))
for _ in range(n):
    operation = input("Enter the operation (ADD/DELETE item_name quantity): ").split()
    if operation[0] == "ADD":
        item_name, quantity = operation[1], int(operation[2])
        add_item(item_name, quantity)
    elif operation[0] == "DELETE":
        item_name, quantity = operation[1], int(operation[2])
        delete_item(item_name, quantity)
    else:
        print("Invalid operation. Use ADD or DELETE.")