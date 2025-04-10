import sales

while True:
    print("\nMeniu:")
    print("1. Creare lista")
    print("2. Afisare lista")
    print("3. Adaugare produs")
    print("4. Modificare produs")
    print("5. Stergere produs")
    print("6. Afisare cost total")
    print("7. exit")

    optiune = input("Alege optiunea: ")
    print("\n")
    if int(optiune) == 1:
        sales.sales.clear()
        print("Lista a fost resetata: ")
    if int(optiune) == 2:
        sales.show_products()
    if int(optiune) == 3:
        name = input("Nume: ")
        price = input("Price: ")
        quantity = input("Quantity: ")
        sales.add_product(name, price, quantity)
    if int(optiune) == 4:
        name = input("Nume: ")
        price = input("Price: ")
        quantity = input("Quantity: ")
        sales.modify_product(name, price, quantity)
    if int(optiune) == 5:
        name = input("Nume: ")
        sales.delete_product(name)
    if int(optiune) == 6:
        sales.show_profit()
    if int(optiune) == 7:
        break
