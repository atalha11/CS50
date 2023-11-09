months_of_year = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
]

button = 0
#buna karışma

while True:
    date = input("Date: ")
    try:
        month, day, year = date.split("/")
        iyear = year.replace(" ","")

        i_month = int(month)
        ix_month = f"{i_month:02d}"
# variable ın adını değiştirmek için önce iday sonra ix day olarak yaptım
        i_day = int(day)
        ix_day = f"{i_day:02d}"

        if i_month < 0 or i_month > 12:
            pass
        elif i_day > 31:
            pass
        else:
            print(f"{iyear}-{ix_month}-{ix_day}")
            break

    except ValueError:
        month, day_with_comma, year = date.split()

        day = day_with_comma.replace("," , "")

        if month in months_of_year:
            for i in range (12):
                if month == months_of_year[i]:
                    i += 1
                    month = i

                    i_day = int(day)
                    ix_day = f"{i_day:02d}"

                    ix_month = f"{month:02d}"

                    if month < 0 or month > 12:
                        pass
                    elif i_day > 31:
                        pass
                    else:
                        print(f"{year}-{ix_month}-{ix_day}")
                        button = 1
                        break
            if button == 1: break


