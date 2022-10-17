# TODO
def main():
    height = 0
    while height < 1 or height > 8:
        height = int(input("Type an integer between 1 and 8 "))

    for i in range(height):
        for j in range(height - (i + 1)):
            print(" ", end="")
        for k in range(i + 1):
            print("#", end="")
        print("  ", end="")
        for l in range(i + 1):
            print("#", end="")
        print("")

if __name__ == "__main__":
    main()