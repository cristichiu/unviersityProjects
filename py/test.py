a = "A&B^C"
i = 0
arr = []
for c in a:
    i+=1
    if c == '&' or c == '^':
        obj = { "infront": a[0:i], "operand": c, "outfront": a[i] }
        arr.append(obj)
print(arr)
