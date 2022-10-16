def main():
    height = get_height()
    for i in range(height):
        print("#")

def get_height():
    while True:
        try:
            x = int(input("Size: "))
            if n > 0:
                break
        except ValueError:
                print("That is not an int!")
                exit()
    return n

main()
