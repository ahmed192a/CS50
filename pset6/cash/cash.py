
dollars = -1
while dollars < 0:
    dollars = input("Change owed: ")
    try:
        dollars = float(dollars)
    except ValueError or SyntaxError:
        dollars = -1

cents = round(dollars * 100)
# counting the coins
z0 = cents % 25
coins = (cents - z0) / 25
z1 = z0 % 10
coins += (z0 - z1) / 10
z0 = z1 % 5
coins += (z1 - z0) / 5
coins += z0
print(coins)