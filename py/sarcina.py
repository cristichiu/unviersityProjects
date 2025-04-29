import re
test = ['abc10','bca09','cab20','abc30','cab18','abc00','cab11','aad19']
rezult = []
for t in test:
    rezult.append(re.search("^[abc]{3}(1[0-9]|20)$", t) != None)
print(rezult)
