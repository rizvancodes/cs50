# TODO
#get card number as string, cast as list
def main():
    cardNum = list(input("Type your card number: "))
    print(cardNum)
    odd = cardNum[-2::-2]
    even = cardNum[-1::-2]
    checksum = 0
    for j in odd:
        checksum += sum(getDigits(int(j) * 2))
    for k in even
    checksum += sum(getDigits for k in even)
    print(checksum)

def getDigits(x):
        return [int(i) for i in str(x)]

if __name__ == "__main__":
    main()

#get alternate digits starting at -2, multiply by 2 and store as string
#take each digit, cast as int and sum
#get alternate digits starting at -1, cast as int and sum
#if modulo is zero then True