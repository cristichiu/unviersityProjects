# Sarcina 1

# exercitiu B

array = ["test0", "test1", "test2", "test3", "test4", "test5"]

print(array[0])
print(array[2])

print(array)
array[1] = "update1"
print(array)

print(array[0:3])

array.insert(1, "test")
print(array)

print(len(array))
print(sorted(array))

array += ["test6"]
print(array)
print("test6" in array)
print("test5" not in array)
print(array * 2)

# exercitiu C

tuplu = (1, 2, 3)
print(type(tuplu))
print(tuplu[0])
print(tuplu[-1])
print(tuplu[0:2])

print(max(tuplu))
print(min(tuplu))
print(len(tuplu))

# exercitiu D

sets = {1, 2, 3, 4, 5, 5, 3, 4}
print(sets)
sets.pop()
print(sets)
print(len(sets))

# exercitiu E

dic1 = {
    "name": "Nume",
    "age": 123
}

dic2 = {
    1: "Nume",
    2: 123
}

print(dic1.get("name"))
print(dic1["age"])
print(dic2[1])
print(dic2[2])
dic2.pop(2)
print(dic2)
print(min(dic1))
print(len(dic2))

# exercitiu F

dic1 = False
print(dic1)

# Sarcina 2

# exercitiu A

numList = [1, 2, 3]
textList = ["prod1", "prod2", "prod3"]

for i in range(min(len(numList), len(textList))):
    print("{}. {}".format(numList[i], textList[i]))

# exercitiu B

age = 0
while 1:
    age = input("Your age: ")
    if age.isnumeric():
        break
    else:
        print("Nu ai introdus o varsta numerica")

age = int(age)
age += 15
print("in 15 ani veti avea " + str(age) + " ani")
