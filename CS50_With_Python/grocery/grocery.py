my_dict = {}
i = 1
while True:

    try:
        item = input().lower()

        if not (item in my_dict):
            i = 1
            my_dict.update({item : i})
        else:
            for x in my_dict:
                if (x == item):
                    i += 1
            my_dict.update({item : i})

    except EOFError:
        break

sorted_dict = dict(sorted(my_dict.items(), key=lambda item: item[0]))

#print(sorted_dict)

for item in sorted_dict:
	print(sorted_dict[item], item.upper())
