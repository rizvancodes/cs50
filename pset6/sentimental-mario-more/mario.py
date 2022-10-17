# TODO
def main():
    height = 0
    while height < 1 or height > 8:
        height = int(input("Type an integer between 1 and 8 "))

    for i in range(height):
        for i in range(height - i):
            print(" ", end="")
        for i in range(i):
            print("#", end="")
        print("  ", end="")
        for i in range(i):
            print("#")

if __name__ == "__main__":
    main()