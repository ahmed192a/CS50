from math import *
def sum(x):
    summ = 0
    while x != 0:
        summ += int(x % 10)
        x = int((x - (x % 10)) / 10)
    return summ

sum1 = 0
sum2 = 0
d = 0
count = 0
# card1 = input("Number: ")
card1 = 0

while card1 == 0:
    card3 = input("Number: ")
    try:
        card1 = int(card3)
    except ValueError or SyntaxError:
        card1 = 0

#print(card1)
card2 = card1

#t0 = int ((card1 - (card1 % 100000000000000)) / 100000000000000)
#if(int ((card1 - (card1 % 1000000000000000)) / 1000000000000000) == 0):
#    t0 = int ((card1 - (card1 % 10000000000000)) / 10000000000000)
#elif((card1 - (card1 % 10000000000000)) / 10000000000000 == 0):
#    t0 = int((card1 - (card1 % 10000000000)) / 10000000000)

#4222222222222
for i in range(ceil(len(card3)/2)):
    d = card1 % 10
    #print(d)
    # sum of the digits that weren’t multiplied by 2
    sum2 += d
    card1 = (card1 - d) / 10
    d = card1 % 10
    # sum of the  products’ digits
    sum1 += int(sum(d * 2))
    card1 = int((card1 - d) / 10)
    count += 1
    #print (card1)

t0 = int((card2 - (card2 % pow(10,(len(card3) - 2)))) / pow(10,(len(card3) - 2)))
print(count)
print(t0)

#print(sum1)
#print(sum2)

v0 = int(sum2 + sum1)
#print(v0)

if (v0 % 10 != 0 or card2 % 1000000000000 == 0):
    # //*** problem ***//
    # //  American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers
    print("INVALID")

elif (v0 % 10 == 0):
    if (t0 == 51 or t0 == 52 or t0 == 53 or t0 == 54 or t0 == 55):
        print("MASTERCARD")
    elif (t0 == 34 or t0 == 37):
        print("AMEX")

    elif ((t0 - (t0 % 10)) / 10 == 4):
        print("VISA")
else:
    print("INVALID")
