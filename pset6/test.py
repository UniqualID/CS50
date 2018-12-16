def addDigit(num):
    numstr = str(num)
    return int(numstr[0]) + (int(numstr[1]) if num > 9 else 0)

print(addDigit(10))