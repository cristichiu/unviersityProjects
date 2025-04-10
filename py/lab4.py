# def inputNum(min, max, inpMess, errMess):
#     inp = ""
#     while True:
#         inp = input(inpMess)
#         if inp.isdigit() and int(inp) >= 20 and int(inp) <= 120:
#             inp = int(inp)
#             break
#         print(errMess)

def calcIdeal():
    varsta = ""
    inaltime = ""
    greutate = ""
    sex = ""
    while True:
        varsta = input("Varsta ta (20-120): ")
        if varsta.isdigit() and int(varsta) >= 20 and int(varsta) <= 120:
            varsta = int(varsta)
            break
        print("Varsta trebuie sa fie un numar intre 20-120")
    while True:
        inaltime = input("Inaltimea ta (150-220): ")
        if inaltime.isdigit() and int(inaltime) >= 150 and int(inaltime) <= 220:
            inaltime = int(inaltime)
            break
        print("Inatimea trebuie sa fie un numar intre 150-220")
    while True:
        greutate = input("Greutatea ta (45-300): ")
        if greutate.isdigit() and int(greutate) >= 45 and int(greutate) <= 300:
            greutate = int(greutate)
            break
        print("Greautate trebuie sa fie un numar intre 150-220")
    while True:
        sex = input("Sexul (M/F): ")
        if sex == "M" or sex == "F":
            break
        print("Sexul poate fi ori M ori F")
    greutateIdeala = 0
    if sex == "M":
        greutateIdeala = inaltime - 100 - ((inaltime - 150)/4 + (varsta - 20)/4)
    elif sex == "F":
        greutateIdeala = inaltime - 100 - ((inaltime - 150)/2.5 + (varsta - 20)/6)
    if(greutate - greutateIdeala > 0):
        print(f"Esti un pic mai greu decat trebuie, slabeste: {greutate - greutateIdeala} kg")
    else:
        print(f"Esti mai usor decat trebuie, mai creste in greutate cu: {-(greutate - greutateIdeala)} kg")

def varstaPisica():
    maiMica = ""
    while maiMica != "Da" and maiMica != "Nu" and maiMica != "Yes" and maiMica != "No":
        maiMica = input("Este pisica ta mai mica de un an (Yes/No sau Da/Nu): ")
    if maiMica == "Yes" or maiMica == "Da":
        pisicOmDic = {
            1: "6 luni",
            2: "10 luni",
            3: "2 ani",
            4: "5 ani",
            5: "8 ani",
            6: "14 ani",
            7: "15 ani",
            8: "16 ani",
            9: "16 ani",
            10: "17 ani",
            11: "17 ani"
        }
        varstaPisic = ""
        while True:
            varstaPisic = input("Ce varsta are pisicul dumneavoastra (1-11 luni): ")
            if varstaPisic.isdigit() and int(varstaPisic) >= 1 and int(varstaPisic) <= 11:
                varstaPisic = int(varstaPisic)
                break
            print("Varsta pisicului trebuie sa fie intre 1 si 11 luni")
        print(f"Pisicul dumneavoastra are {pisicOmDic[varstaPisic]} in ani omenesti")
    else:
        varstaPisic = ""
        while True:
            varstaPisic = input("Ce varsta are pisicul dumneavoastra (1-35 ani): ")
            if varstaPisic.isdigit() and int(varstaPisic) >= 1 and int(varstaPisic) < 35:
                varstaPisic = int(varstaPisic)
                break
            print("Varsta pisicului trebuie sa fie intr 1 si 35 ani")
        varstaPisicOm = 0
        for i in range(1, varstaPisic+1):
            if i == 1:
                varstaPisicOm += 18
            elif i == 2:
                varstaPisicOm += 7
            elif i >= 3 and i <= 15:
                varstaPisicOm += 4
            else:
                varstaPisicOm += 3
        print(f"Pisicul dumneavoastra are {varstaPisicOm} ani in ani omenesti")
varstaPisica()
