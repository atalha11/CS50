kelime = input("Here goes your text: ")

for harf in kelime:
        if(harf.isupper()):
                print("_" + harf.lower(), end="")

        else:
                print(harf, end="")

print()

