word = 1
letter = 0
sentence = 0

text = input("Text: ")
text_length = len(text)

# letter saymak

for i in range(text_length):
    if (text[i].isalpha()):
        letter += 1

# word sayar:

for i in range (text_length):
    if (text[i].isspace()):
        word += 1

#sentence sayar:

for i in range (text_length):
    if (text[i] == '.' or text[i] == '?' or text[i] == '!'):
        sentence += 1

index = round((0.0588 * letter / word * 100) - (0.296 * sentence / word * 100) - 15.8)

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")