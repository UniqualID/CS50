/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdint.h>
int main()
{
    FILE* memcard = fopen("card.raw", "rb");

    // buffer of 512 bytes
    uint8_t buffer[512];


    int firstimg = 1;
    FILE* img = NULL;

    //used for file naming
    int number = 1;
    char number_str[] = "000.jpg ";

    while(fread(&buffer, 512, 1, memcard) == 1)
    {

        //if beginning of jpg found
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            // if this is the first jpg, then read into memory
            if(firstimg)
            {
                img = fopen("000.jpg","wb");
                fwrite(&buffer, 512, 1, img);
                firstimg = 0;
            }
            //if not the first jpg
            else
            {
                //close previous jpg
                fclose(img);

                //find name for new jpg
                sprintf(number_str, "%03d.jpg",number);
                number++;

                img = fopen(number_str, "wb");
                //open new jpg & write to it
                fwrite(&buffer, 512, 1, img);
            }


        }

        // else if not the beginning of a jpg
        else
        {
            if(firstimg)
                continue;
            else
            {
                fwrite(&buffer, 512, 1, img);
            }

        }
    }

    fclose(img);
    fclose(memcard);
}
