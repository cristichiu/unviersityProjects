import functions

def Sarcina1():
    i = sum = 0
    while i <= 4:
        sum += i
        i = i+1
    print(sum)

    for char in "PYTHON STRING":
        if char == ' ':
            break
        print(char, end='')
        if char == "O":
            continue
        print ('*', end='')

def Sarcina2():
    lista = [1,2,3,4,1,2,1,1,2,4,6]
    dic = {
        1: "test",
        2: "l",
        3: "test",
        4: "a"
    }
    string = "Acesta este un string ca sa vad ceva"

    listaFind = ""
    dicFind = ""
    stringFind = ""
    while True:
        listaFind = input("Ce sa numar in lista (number): ")
        if listaFind .isdigit():
            listaFind = int(listaFind)
            break
        print("Inputul trebuie sa fie un numar")
    dicFind = input("Ce sa numar in dictionar (string): ")
    while True:
        stringFind = input("Ce sa numar in string (caracter): ")
        if len(stringFind) == 1:
            break
        print("Inputul trebuie sa fie un caracter")
    listaC = dicC = stringC = 0
    for l in lista:
        if l == listaFind:
            listaC+=1
    for d in dic:
        if dic[d] == dicFind:
            dicC+=1
    for s in string:
        if s == stringFind:
            stringC+=1
    print(f"Am numarat {listaC} de {listaFind} in lista")
    print(f"Am numarat {dicC} de {dicFind} in dictionar")
    print(f"Am numarat {stringC} de {stringFind} in string")

while True:
    print("""
1. Afiseaza lista curenta de produse
2. Adauga un produs in lista
3. Sterge un produs
4. exit
    """)
    opt = input("Optiune: ")
    print("")
    if opt == "1":
        functions.show()
    elif opt == "2":
        newProduct = input("Ce produs vrei sa adaugi: ")
        functions.add(newProduct)
    elif opt == "3":
        print(functions.remove())
    elif opt == "4":
        break
    else:
        print("Optiune invalida")
