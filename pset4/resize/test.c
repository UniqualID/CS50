#include <stdio.h>
#include <stdlib.h>
int main()
{
    int intar[] = {1,2,3,4};
    int intar2* = malloc(sizeof(int) * 4);
    int intar3[] = malloc(sizeof(int) * 4);
    printf("%ld\t%ld\t%ld\n", sizeof(intar), sizeof(intar2), sizeof(intar3));
    return 0;
}