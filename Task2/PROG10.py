import re
def parse_encoded_string(encoded_string):
    parts = re.split('0+', encoded_string)
    new_parts = []
    for part in parts:
        if part:
            new_parts.append(part)
    if len(new_parts) >= 3:
        first_name, last_name, id_no = new_parts[:3]
        result ={"first_name": first_name,"last_name": last_name,"id": id_no}
        return result
    else:
        return None

import os
os.system("cls")
encoded_string = input("Enter the encoded string: ")
parsed_string = parse_encoded_string(encoded_string)

if parsed_string:
    print(parsed_string)
else:
    print("Invalid input")