# TODO
#get card number as string, cast as list
cardNum = list(input("Type your card number: "))
print(cardNum)
newList = ()
for i in cardNum[::2]:
    newList = [str(int(i) * 2).split for i in newList]
print(altsum)
print(newList)
#get alternate digits starting at -2, multiply by 2 and store as string
#take each digit, cast as int and sum
#get alternate digits starting at -1, cast as int and sum
#if modulo is zero then True