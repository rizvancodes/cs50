def main():
    height = get_height()
    for i in range(height):
        print("#")

def get_height():
    while True:
        try:
            x = int(input("Size: "))
        except:
                print("That is not an int!")
                exit()
