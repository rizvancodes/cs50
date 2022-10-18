# TODO
#get card number as string, cast as list
cardNum = list(input("Type your card number: "))
print(cardNum)
altsum = 0
for i in cardNum[::2]:
    altsum += int(i) * 2
print(altsum)
#get alternate digits starting at -2, multiply by 2 and store as string
#take each digit, cast as int and sum
#get alternate digits starting at -1, cast as int and sum
#if modulo is zero then True