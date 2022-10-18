# TODO
sampleString = input("Enter your text: ")
alpha = 0
words = 0
sentences = 0

for i in sampleString:
    if(i.isalpha()):
        alpha += 1

wordList = sampleString.split()
words = len(wordList)

sentenceList = sampleString.split(".")
sentences = len(sentenceList) - 1

print(alpha)
print(words)
print(sentences)