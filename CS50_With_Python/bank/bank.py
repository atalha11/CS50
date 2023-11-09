x = input("Greeting: ")
x = x.lower()
x = x.strip()
dollars = 0

if "hello" in x:
    dollars += 0
elif x.startswith("h"):
    dollars += 20
else:
    dollars += 100

print(f"${dollars}")