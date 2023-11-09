def main():
    plate = input("Plate: ")

    if (is_valid(plate) == False):
        print("Invalid")
    else:
        print("Valid")


def is_valid(plate):

    length = len(plate)

    if (length > 6 or length < 2):
        validation = False
        return validation
    
    if (plate.isalpha()):
        validation = True
        return validation

    if (plate[0].isalpha() and plate[1].isalpha()):
        zort = 5
    else:
        validation = False
        return validation

    marker = 2

    if(plate[marker] == "0"):
            validation = False
            return validation

    while(marker <= length):
        if (plate[marker].isnumeric()):
            break
        else:
            marker += 1

    # marker += 1 BU YANLIŞTI

    if(plate[marker:length].isnumeric()):
        zort = 6
    else:
        validation = False
        return validation


main()
