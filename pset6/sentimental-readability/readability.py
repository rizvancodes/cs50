# TODO
import re

sampleString = input("Enter your text: ")
alpha = 0
words = 0
sentences = 0

for i in sampleString:
    if(i.isalpha()):
        alpha += 1

wordList = sampleString.split()
words = len(wordList)

sentenceList = re.split(".")
sentences = len(sentenceList) - 1

grade = 0.0588 * alpha/words * 100 - 0.296 * sentences/words * 100 - 15.8



print(alpha)
print(words)
print(sentences)
print(grade)