# TODO
def main():
    height = 0
    while height < 1 or height > 8:
        height = int(input("Type an integer between 1 and 8 "))

    for i in range(1, height):
        for j in range(1, height - i):
            print(" ", end="")
        for k in range(1, height):
            print("#", end="")
        print("  ", end="")
        for l in range(1, height):
            print("#")

if __name__ == "__main__":
    main()