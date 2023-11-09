def main():
    get_percentage()

def get_percentage():
    while True:
        try:
            fraction = input("Fraction: ")
            x,y = fraction.split("/")
            x = int(x)
            y = int(y)
            z = x / y

            if(z < 0 or z > 1):
                pass
            else:
                if (z >= 0.99):
                    print("F")
                elif (z <= 0.01):
                    print("E")
                else:
                    print("{:.0%}".format(z))

                break

        except ValueError:
            pass
        except ZeroDivisionError:
            pass
main()
