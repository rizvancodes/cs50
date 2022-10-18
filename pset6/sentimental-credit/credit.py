# TODO
#get card number as string, cast as list
def main()
    cardNum = list(input("Type your card number: "))
    print(cardNum)
    odd = cardNum[-2::-2]
    even = cardNum[-1::-2]
    checksum = 0

def digits_of(n):
        return [int(d) for d in str(n)]
#get alternate digits starting at -2, multiply by 2 and store as string
#take each digit, cast as int and sum
#get alternate digits starting at -1, cast as int and sum
#if modulo is zero then True