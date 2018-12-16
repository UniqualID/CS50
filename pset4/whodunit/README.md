# Questions

## What's `stdint.h`?

Library that defines primitives of specific sizes. Can be used when working across platforms when the sizes of primitives aren't certain. ie - int is 2 bytes instead of 4

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Same across all platforms

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1,4,4,2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

BM

## What's the difference between `bfSize` and `biSize`?

bfsize is the size in bytes of the bitmap, bisize is the size of the bitmapinfoheader struct

## What does it mean if `biHeight` is negative?

originates at the top left corner

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

file aint there

## Why is the third argument to `fread` always `1` in our code?

cause u only want to read the size of the struct once

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

sets the file position of the stream to the given offset

## What is `SEEK_CUR`?

Current position of the file pointer
