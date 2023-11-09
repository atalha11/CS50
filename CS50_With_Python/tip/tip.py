def main():
    dollars = dollars_to_float(input("How much was the meal? "))
    percent = percent_to_float(input("What percentage would you like to tip? "))
    tip = dollars * percent / 100
    print(f"Leave ${tip:.2f}")

def dollars_to_float(d):
    #
    dolarsız = float(d.replace('$' , ''))
    return dolarsız

def percent_to_float(p):
    #
    yuzdesiz = float(p.replace('%' , ''))
    return yuzdesiz


main()