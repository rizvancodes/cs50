# TODO
def main():
    height = 0
    while height < 1 or height > 8:
        height = int(input("Type an integer between 1 and 8 "))

    for i in range(height):
        print(i)
        for j in range(height):
            print("#", end="")



if __name__ == "__main__":
    main()