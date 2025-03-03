# Sarcina 1
print("Sarcina 1")
'''
Acesta este un comentariu din mai multe linii
El nu face nimic in cod
''' #ex 4

name = input("Your name: ") #ex 3
a = 12 #ex 5
b = 3.14 #ex 5
c = "test" #ex 5
d = """Acesta este un string
care contine mai multe linii""" #ex 5

print("Salut " + name) #ex 3
print(type(b)) #ex 6
print(type(c)) #ex 6
print(len(d)) #ex 7
print(c.upper()) #ex 8
print(d[0:10]) #ex 9

print("Numele tau este {}".format(name)) #ex 11
print(f"Sunt sigur ca numele tau este {name}") #ex 11

# Sarcina 2
print("Sarcina 2")

#ex a
txt = "More results from text..."
substr = txt[4:12]
print(substr)
print(substr.strip())

#ex b
print(txt.split())

#ex c
age = input("Your age: ")
txt = "My name is {}, and I am {}"
print(txt.format(name, age))
