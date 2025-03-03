# ex 1
greet_user = lambda name : print("Hello My Dear,", name)
user_name = input("What is your name?")
greet_user(user_name)

# ex 2
lista = [(3, 11), (1, 7), (7, 8), (16, 88), (23, 15)]
a = lambda t : t[1]
print(sorted(lista, key=a))

# ex 3
multiply = lambda x, y : x*y
print(multiply(2, 3))

# ex 4 a
def noParam():
    print("functie fara parametri")
def params(name):
    print("functie cu parametri", name)
def preDefParams(name="no name"):
    print("functie cu parametri predefiniti", name)


# ex 4 b
def withReturn(a, b):
    return a * b
def noReturn(a, b):
    print("fara return: ", a * b)

# ex 5
noParam()
params("test1")
preDefParams("test2")
preDefParams()

print("cu return: ", withReturn(2, 8))
noReturn(2, 8)
