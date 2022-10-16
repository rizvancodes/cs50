
try:
    x = int(input("Type your first number "))
except:
        print("That is not an int!")
        exit()
try:
    y = int(input("Type your second number "))
except:
    print("That is not an int!")
    exit()
print(x + y)
