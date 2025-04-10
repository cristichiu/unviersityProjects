import re
def add():
    name = input("Nume angajat: ")
    surname = input("Prenume angajat: ")
    department = input("Departament: ")
    childrens = input("Numarul de copii: ")
# ^[a-zA-z-]{2,20}$ name/surname
# ^([a-zA-z](-?)){2,20}$ better name/surname
# ^([a-zA-z]((-[a-zA-Z])?)){2,20}$ better then better for surname/name
# ^[a-zA-Z0-9]+( |)[a-zA-Z0-9]+$ department
# ^[a-zA-Z]+ ?[0-9]+$ departament
# ^([0-9]|1[0-9])$ copii
    error = ""
    if re.search("^([a-zA-z]((-[a-zA-Z])?)){2,20}$", name) == None:
        error += "Numele nu este valid.\n"
    if re.search("^([a-zA-z](-?)){2,20}$", surname) == None:
        error += "Prenumele nu este valid.\n"
    if re.search("^[a-zA-Z]+ ?[0-9]+$", department) == None:
        error += "Departamentul nu este valid.\n"
    if re.search("^([0-9]|1[0-9])$", childrens) == None:
        error += "Campul copii nu este valid.\n"
    if error != "":
        print(error)
        print("Trebuie sa introduci din nou datele")
        add()
    else:
        datafile = open("data.txt", "a")
        department.replace(" ", "_")
        datafile.write(f"{name}\t{surname}\t{department}\t{childrens}\n")
        datafile.close()

def readFileData():
    datafile = open("data.txt", "r")
    lines = datafile.read().split("\n")
    lines.pop()
    data = []
    for line in lines:
        line = line.split("\t")
        data.append({"name":line[0], "surname":line[1], "department": line[2], "childrens": int(line[3])})
    datafile.close()
    return data

def show():
    data = readFileData()
    print("\nAngajati cu copii:\n")
    sum = 0
    for member in data:
        if member["childrens"] > 0:
            print(f"nume: {member['name']}\nprenume: {member['surname']}\ndepartament: {member['department']}\ncopii: {member['childrens']}\n")        
            sum += member['childrens']
    print(f"Suma totala de copii: {sum}\n")
    print("Angajati fara copii:\n")
    for member in data:
        if member["childrens"] == 0:
            print(f"nume: {member['name']}\nprenume: {member['surname']}\ndepartament: {member['department']}\ncopii: {member['childrens']}\n")        

def searchMember():
    data = readFileData()
    while True:
        print("""
1. Cauta dupa nume
2. Cauta dupa prenume
3. Cauta dupa departament
4. Cauta dupa numarul de copii
        """)
        option = input("Optiunea ta:")
        print("\n")
        if option == "1":
            search = input("Numele: ")
            for member in data:
                if member["name"] == search:
                    print(f"nume: {member['name']}\nprenume: {member['surname']}\ndepartament: {member['department']}\ncopii: {member['childrens']}\n")        
            break
        elif option == "2":
            search = input("Prenumele: ")
            for member in data:
                if member["surname"] == search:
                    print(f"nume: {member['name']}\nprenume: {member['surname']}\ndepartament: {member['department']}\ncopii: {member['childrens']}\n")        
            break
        elif option == "3":
            search = input("Departamentul: ")
            for member in data:
                if member["department"] == search:
                    print(f"nume: {member['name']}\nprenume: {member['surname']}\ndepartament: {member['department']}\ncopii: {member['childrens']}\n")        
            break
        elif option == "4":
            search = input("Copii: ")
            for member in data:
                if str(member["childrens"]) == search:
                    print(f"nume: {member['name']}\nprenume: {member['surname']}\ndepartament: {member['department']}\ncopii: {member['childrens']}\n")        
            break
        else:
            print("Optiune invalida.")

while True:
    print("""
1. Adauga membru
2. Afiseaza membri
3. Cauta membru
4. exit
    """)
    option = input("Optiunea: ")
    if option == "1":
        add()
    elif option == "2":
        show()
    elif option == "3":
        searchMember()
    elif option == "4":
        break
    else:
        print("Optiune invalida.")
