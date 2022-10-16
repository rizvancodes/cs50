def main():
    height = get_height()
    for i in range(height):
        print("#", end = "")

def get_height():
    while True:
        try:
            x = int(input("Size: "))
            if x > 0:
                break
        except ValueError:
                print("That is not an int!")
                exit()
    return x

main()
