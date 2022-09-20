def lol(x, y):
    for i in range(x):
        print(" ", end="")
    for i in range(y - x):
        print("#", end="")
    print("  ", end="")
    for i in range(y - x):
        print("#", end="")
    print("")
    if x > 0:
        lol(x - 1, y)


height = 0
while height > 8 or height < 1:
    height = input("Height = ")
    try:
        height = int(height)
    except ValueError or SyntaxError:
        height = 0

lol(height - 1, height)