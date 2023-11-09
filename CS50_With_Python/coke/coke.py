amount = 50
x = 0
print("Amount Due:" , amount)

while(x < 50):
    insert_coin = int(input("Insert Coin: "))

    if (insert_coin == 5):
        x += insert_coin
    elif (insert_coin == 10):
        x += insert_coin
    elif (insert_coin == 25):
        x += insert_coin
    else:
        x += 0

    if (x < amount):
        print("Amount Due:" , amount - x)
    else:
        print("Change Owed:", x - amount)
        break
