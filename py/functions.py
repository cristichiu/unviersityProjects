shoppingList = []
def add(newProduct):
    for s in shoppingList:
        if s == newProduct:
            print("Acest produs deja exista")
            return
    shoppingList.append(newProduct)
def remove():
    deleteProduct = input("Ce produs vrei sa stergi (denumire sau nr de ordine): ")
    if deleteProduct.isdigit() and int(deleteProduct) >= 1 and int(deleteProduct) <= len(shoppingList):
        del shoppingList[int(deleteProduct)-1]
        return "Element sters cu succes"
    else:
        found = False
        for s in shoppingList:
            if s == deleteProduct:
                found = True
                break
        if found:
            shoppingList.remove(deleteProduct)
            return "Element sters cu succes"
        else:
            return "Elementul nu a fost gasit"

def show():
    for index, s in enumerate(shoppingList, start=1):
        print(f"{index}. {s}")
