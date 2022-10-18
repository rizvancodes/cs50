# TODO
#get card number as string, cast as list
def main():
    num = input("Type your card number: ")
    if luhns(num):
        if len(list(num)) == 15:
            if int(list(num)[0] == 3):
                if int(list(num)[1] == 4 or 7):
                    print("AMEX")
                else:
                    print("INVALID")
            else:
                print("INVALID")
        elif len(list(num)) == 16:
            if int(list(num)[0]) == 4:
                print("VISA")
            elif int(list(num)[0]) == 5:
                if int(list(num)[0]) == 1 or 2 or 3 or 4 or 5:
                    print("MASTERCARD")
                else:
                    print("INVALID")
        elif len(list(num)) == 13:
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


def luhns(str):
    cardNum = list(str)
    odd = cardNum[-2::-2]
    even = cardNum[-1::-2]
    checksum = 0
    for j in odd:
        checksum += sum(getDigits(int(j) * 2))
    for k in even:
        checksum += int(k)
    return checksum % 10 == 0

def getDigits(x):
    return [int(i) for i in str(x)]

if __name__ == "__main__":
    main()

#get alternate digits starting at -2, multiply by 2 and store as string
#take each digit, cast as int and sum
#get alternate digits starting at -1, cast as int and sum
#if modulo is zero then True