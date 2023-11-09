# Kodun açıklamasını en alta yazıyorum

def main():
    x = input("What time is it? ")
    y = convert(x)

    if 7.00 <= y <= 8.00:
        print("breakfast time")
    elif 12.00 <= y <= 13.00:
        print("lunch time")
    elif 18.00 <= y <= 19.00:
        print("dinner time")


def convert(x):
    hours, minutes = x.split(":")
    hours = float(hours)
    minutes = float(minutes) / 60
    time = hours + minutes
    return time

    # mesela 7.30 derse 7.5 saat olması lazım o ancak dakikayı 60 a bölmekle olur (30/60) = 0.5 sonra 7 + 0.5 = 7.5


    # burayı anlamadım bak
if __name__ == "__main__":
    main()


# İlk olarak saati sorduk. 7:30 diye girdi mesela. Bunu convert() in içine attık
# Convert bunu : nın sağı ve solu diye ikiye ayırdı ve hours minutes isimli iki variable a atadı.
# hours string olduğu için type casting yaptık
# aynısını minutes için de yaptık ve 60 a böldük sebebini yukarıdaki commentte açıkladım
# sonra 7:30 için 7.00 + 0.50 yi topladığıımız time variable ını main() fonksiyona returnledik.
# sonra bunu aralıklarda mı diye kontrol ettik ve print ettik.