a, b, c = input("Expression: ").split()
# splitin assing özelliğini kullanalım

a = float(a)
c = float(c)
sonuc = 0

if b == "+":
    sonuc = a + c
elif b == "-":
    sonuc = a - c
elif b == "/":
    sonuc = a / c
elif b == "*":
    sonuc = a * c
else:
    print("Hata")

print(sonuc)

"""
şöyle de başlanabilirdi ama splitin assign etme özelliğini kullandık:

x = input("Expression: ").split()

a = float(x[0])
b = x[1]
c = float(x[2])
sonuc = 0

"""