import re
while True:
    try:
        number = input("Introdu numarul tau: ")
        if re.search("(^(\+373|00373)([0-9]){8}$|^[0-9]{8}$)", number) == None: int("a")
    except:
        print("Numarul tau a fost scris incorect.")
    else:
        print(f"Bravo numarul tau este corect scris corect: {number}")
        break
