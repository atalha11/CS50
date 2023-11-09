from cs50 import get_float

while True:
    dollars = get_float("Change owed: ")
    if dollars > 0:
        break

cents = round(dollars * 100,0)
coins = 0

while cents >= 25:
    cents = cents - 25
    coins = coins + 1

while cents >= 10:
    cents = cents - 10
    coins = coins + 1

while cents >= 5:
    cents = cents - 5
    coins = coins + 1

print (coins)
