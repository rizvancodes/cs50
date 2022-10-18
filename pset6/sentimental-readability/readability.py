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

sentenceList = re.split(r'[.!?]', sampleString)
sentences = len(sentenceList) - 1

grade = round(0.0588 * alpha/words * 100 - 0.296 * sentences/words * 100 - 15.8)

if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print(f"Grade: {grade}")