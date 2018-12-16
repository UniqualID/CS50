#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void rotate(string str, int by)
{
    by = by % 26;
    for(int x = 0; x < by; x++)
    {
        for(int i = 0; i < strlen(str); i++)
        {
            if(!isalpha(str[i]))
                continue;
            if(str[i] == 'z')
            {
                str[i] = 'a';
                continue;
            }
            if(str[i] == 'Z')
            {
                str[i] = 'A';
                continue;
            }
            str[i]++;
        }

    }
}
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    int rotateby = atoi(argv[1]);
    printf("plaintext: ");
    string text = get_string();
    rotate(text,rotateby);
    printf("ciphertext: %s\n", text);
    return 0;
}