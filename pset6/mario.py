from cs50 import get_int
while True:
    height = get_int("Height: ")
    if height > 0 and height <= 23:
        break
steps = 1
spaces = height - 1

for i in range(height):
    print(' ' * spaces, end = "")
    print('#' * steps, end = " ")
    print('#' * steps, end = "")
    print(' ' * spaces, end = "\n")
    spaces-=1
    steps+=1
