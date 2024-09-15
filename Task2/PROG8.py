def Morse(text):
    morse_code_dict = {
        'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.', 'H': '....',
        'I': '..', 'J': '.---', 'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.',
        'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-',
        'Y': '-.--', 'Z': '--..',
        '0': '-----', '1': '.----', '2': '..---', '3': '...--', '4': '....-', '5': '.....', '6': '-....',
        '7': '--...', '8': '---..', '9': '----.',
        ',': '--..--', ':': '---...', "'": '.----.', '!': '-.-.--', '.': '.-.-.-', '?': '..--..', ' ': '/'
    }

    text = text.upper()
    morse_code = []

    for char in text:
        if char in morse_code_dict:
            morse_code.append(morse_code_dict[char])
        else:
            morse_code.append(char)

    return ' '.join(morse_code)

import os
os.system("cls")
text_input = input("Enter a string to translate to Morse code: ")
translated_text = Morse(text_input)
print("Morse code:", translated_text)