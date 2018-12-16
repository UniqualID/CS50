from cs50 import get_int

def addDigit(num):
    numstr = str(num)
    return int(numstr[0]) + (int(numstr[1]) if num > 9 else 0)


orig = get_int("Enter a number: ")
s_last = orig*10
ss_last = orig * 100
s_lastSum = 0

while(True):
    s_last = s_last // 100

    if s_last == 0:
        break
    else:
        s_lastSum = s_lastSum + addDigit(2 * (s_last%10))
        print("{}\t{}\t{}".format(s_last%10,addDigit(2 * (s_last%10)), s_lastSum))

while(True):
    ss_last = ss_last // 100

    if ss_last == 0:
        break

    else:
        s_lastsum = s_lastsum + ss_last%10
print(s_lastsum)
