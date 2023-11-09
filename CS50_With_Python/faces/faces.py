def main():
    x = input('Enter the text: ')
    print(convert(x))


def convert(x):
    y = x.replace(':)', '🙂')
    z = y.replace(':(', '🙁' )
    return z


main()