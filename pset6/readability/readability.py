from math import *
def letters_num(y):
    #count the letters
    count = 0
    for i in range(len(y)):
        # check if the the char if alphabetical
        if ((y[i] >= 'a'  and y[i] <= 'z') or (y[i] >= 'A'  and y[i] <= 'Z')):
            count += 1
    return count


def word_num(x):
    #count the words
    count = 0
    for i in range(len(x)):
        # check if the the char if space
        if (x[i] == ' '):
            count += 1
    return count + 1


def sent_num(x):
    #count of the sentence
    count = 0
    for i in range(len(x)):
        # check the end of the sentance
        if (x[i] == '.'  or x[i] == '!'  or x[i] == '?'):
            count += 1
    return count


def Avg (x, y):
    #get the average per 100 word
    return x * 100 /  float(y)







# get the text
inp = input("Text: ")
# parameters of the The Coleman-Liau index
L = Avg (letters_num(inp ), word_num(inp))
S = Avg (sent_num(inp),  word_num(inp))
#The Coleman-Liau index formula
G = round(0.0588 * L - 0.296 * S - 15.8)
if (G >= 16):
    print("Grade 16+")
elif (G < 1):
    print("Before Grade 1")
else:
    print("Grade", G)







