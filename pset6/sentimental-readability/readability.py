# TODO
sampleString = input("Enter your text: ")
alpha = 0
words = 0
sentences = 0
for i in sampleString:
    if(i.isalpha()):
        alpha += 1
print(alpha)