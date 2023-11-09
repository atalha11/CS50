sentence = input("Input: ")

# output yazısını her harften sonra tekrar yazmamak için baştan yazdık
print("Output: ", end="")

# harf harf gezip sesli yakalamaya çalışıyoruz yakalarsak geçiyoruz
# sesli değilse yazdırıyoruz
for letter in sentence:
    if(letter.lower() in ('a', 'e', 'i', 'o', 'u')):
        continue
    elif(letter.upper() in ('A', 'E', 'I', 'O', 'U')):
        continue
    else:
        print(letter, end="")

# en son cursor aşağı insin diye bi print
print()