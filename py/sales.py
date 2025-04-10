sales = []

def add_product(name, price, quantity):
    name = name.lower()
    if any(p['name'] == name for p in sales):
        print("Produsul exista deja")
        return
    if not price.isdigit() or not quantity.isdigit():
        print("Pretul sau cantitatea nu sunt cifre")
        return
    sales.append({'name': name, 'price': int(price), 'quantity': int(quantity)})
    print("Produs adaugat cu succes")

def show_products():
    if not sales:
        print("Nu exista produse in lista")
        return 
    for p in sales:
        print(f"name: {p['name']}\nprice: {p['price']}\nquantity: {p['quantity']}\n\n")

def modify_product(name, price, quantity):
    name = name.lower()
    if not price.isdigit() or not quantity.isdigit():
        print("Pretul sau cantitatea nu sunt cifre")
        return
    for p in sales:
        if p['name'] == name:
            p['price'] = int(price)
            p['quantity'] = int(quantity)
            return
    print("Produsul nu a fost gasit")

def delete_product(name):
    for p in sales:
        if p['name'] == name:
            sales.remove(p)
            return
    print("Acest produs nu exista")

def show_profit():
    profit = 0
    for p in sales:
        profit += p['price'] * p['quantity']
    print(f"Profit: {profit}")
