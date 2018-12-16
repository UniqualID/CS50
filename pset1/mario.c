#include <stdio.h>
#include <cs50.h>

int main()
{
    int height, spacing, stars;
    do
    {
        printf("Height: ");
        height = get_int();
    }while (height > 23 || height <0);
    spacing = height - 1;
    stars = 1;
    
    
    for(int pheight = 0; pheight < height; pheight++)
    {
        //prints spacing
        for(int i = 0; i < spacing; i++)
        {
            putchar(' ');
        }
        //prints first row
        for(int i = 0; i < stars; i++)
        {
            putchar('#');
        }
        printf(" ");
        //prints second row
        for(int i = 0; i < stars; i++)
        {
            putchar('#');
        }
        stars++;
        spacing--;
        putchar('\n');
    }

}