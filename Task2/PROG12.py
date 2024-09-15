class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node

    def delete_ele(self, value):
        if not self.head:
            return
        
        if self.head.data == value:
            self.head=self.head.next
            return
        
        current=self.head
        while current.next:
            if current.next.data == value:
                current.next=current.next.next
                return
            current=current.next

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("NULL")

class Stack:
    def __init__(self):
        self.items = []

    def __str__(self):
        return "Stack: " + str(self.items)
    
    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        else:
            return None

    def is_empty(self):
        return len(self.items) == 0

if __name__ == "__main__":
    import os
    os.system("cls")
    stack = Stack()
    linked_list = LinkedList()

    while True:
        print("\nChoose an operation:")
        print("1. Push to Stack")
        print("2. Pop from Stack")
        print("3. Append to Linked List")
        print("4. Delete element from Linked List")
        print("5. Display Linked List")
        print("6. Quit")

        choice = input("Enter your choice: ")

        if choice == "1":
            item = input("Enter item to push to the stack: ")
            stack.push(item)
            print((item), "pushed to the stack.")
            print(stack)
        elif choice == "2":
            item = stack.pop()
            if item is not None:
                print("Popped item from stack:",(item))
                if item is not None:
                    print(stack)
                else:
                    print("Stack is empty.")
            else:
                print("Stack is empty.")
        elif choice == "3":
            data = input("Enter data to append to the linked list: ")
            linked_list.append(data)
            print((data),"appended to the linked list.")
        elif choice == "4":
            data = input("Enter the data to be deleted from the linked list: ")  
            linked_list.delete_ele(data)
            print((data),"deleted from the linked list.")
        elif choice == "5":
            print("Linked List:")
            linked_list.display()    
        elif choice == "6":
            print("Exiting the program.")
            break
        else:
            print("Invalid choice. Please enter a valid option.")