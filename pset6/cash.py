from cs50 import get_float
import sys

change = get_float("Enter change:\t")
while(change < 0):
    change = get_float("Enter change:\t")

coins = 0
while change >= .25:
    coins = coins+1
    change = change - .25
while change >= .1:
    coins = coins+1
    change = change - .1
while change >= .05:
    coins = coins+1
    change = change - .05
while change >= .01:
    coins = coins+1
    change = change - .01

print(coins)

