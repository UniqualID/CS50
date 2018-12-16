#define _XOPEN_SOURCE
#include <unistd.h>

#include <stdio.h>
#include <string.h>

#include <cs50.h>
#include <stdlib.h>

void reset_all_to_A(char* key)
{
    key[strlen(key)] = 'A';
    for(int i = 0; i < strlen(key); i++)
    {
        key[i] = 'A';
    }
}
//has no option for default parameters killmepls
void increment(char* key, int pos, bool isMainCall)
{
    if(isMainCall)
    {
        pos = strlen(key)-1;
        printf("is maincall, Strlen[key] = %d\t", strlen(key));
    }
    else
        printf("\tisnotmaincall\t");
    string keypos = key[pos]++;

    if (key[pos] == 'Z'+1)
    {
        key[pos] = 'a';
        return;
    }
    else if (key[pos] == 'z'+1)
    {
        //if all positions are 'z's
        if (pos == 0)
        {
            reset_all_to_A(key);
            return;
        }
        key[pos] = 'A';
        increment(key, pos-1, false);
        return;
    }
}

int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    char salt[3];
    strncpy(salt, argv[1], 2);
        printf("The salt is: %s\n", salt);

    char* hashed = argv[1];
    char testpass[6] = "A";
    char* crypted;
    do
    {
        crypted = crypt(testpass, salt);
        printf("Current string: %s\t crypted: %s\t provided: %s\n", testpass, crypted, argv[1]);
        increment(testpass, 0, true);
    }while(strcmp(crypted, argv[1]));
}