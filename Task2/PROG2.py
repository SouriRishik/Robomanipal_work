import os
os.system("cls")
from itertools import permutations
s = input("Enter a string: ")
words = s.split()
sentences = permutations(words)
for sentence in sentences:
    print(sentence)