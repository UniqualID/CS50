        // Copies a BMP file and rescales by factor

        #include <stdio.h>
        #include <stdlib.h>

        #include "bmp.h"

        int main(int argc, char *argv[])
        {
            // ensure proper usage
            if (argc != 4)
            {
                fprintf(stderr, "Usage: ./resize scalefactor infile outfile\n");
                return 1;
            }

            // remember filenames
            int scale = atoi(argv[1]);
            char *infile = argv[2];
            char *outfile = argv[3];

            // open input file
            FILE *inptr = fopen(infile, "r");
            if (inptr == NULL)
            {
                fprintf(stderr, "Could not open %s.\n", infile);
                return 1;
            }

            // open output file
            FILE *outptr = fopen(outfile, "w");
            if (outptr == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Could not create %s.\n", outfile);
                return 1;
            }

            // read infile's BITMAPFILEHEADER
            BITMAPFILEHEADER bf;
            fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

            // read infile's BITMAPINFOHEADER
            BITMAPINFOHEADER bi;
            fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

            // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
            if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
                bi.biBitCount != 24 || bi.biCompression != 0)
            {
                fclose(outptr);
                fclose(inptr);
                fprintf(stderr, "Unsupported file format.\n");
                return 1;
            }

            //store original height, width and padding of the INFILE
            LONG origHeight = bi.biHeight;
            LONG origWidth = bi.biWidth;
            int origPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
            //printf("%d\t%d\t%d\n", origHeight, origWidth, origPadding);



            // Edit headers based on scale factor
            bi.biWidth *= scale;
            bi.biHeight *= scale;
            int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
            bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight);
            bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

            // write outfile's BITMAPFILEHEADER
            fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);


            // write outfile's BITMAPINFOHEADER
            fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

            // create buffer that has enough space to store one row of pixels for the OUTFILE
            int rowsize = sizeof(RGBTRIPLE) * bi.biWidth;
            RGBTRIPLE* rowBuff = malloc(rowsize);

            //RGBTRIPLE rowBuff[bi.biWidth];
            //printf("%lu\t%d\t%lu\t\n", sizeof(RGBTRIPLE), bi.biWidth, sizeof(rowBuff));


            // iterate over infile's scanlines
            for (int i = 0, biHeight = abs(origHeight); i < biHeight; i++)
            {
                int curindex = 0;

                // iterate over pixels of infile scanline
                for (int j = 0; j < origWidth; j++)
                {
                    // temporary storage
                    RGBTRIPLE triple;

                    // read RGB triple from infile
                    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                    // write RGB triple to rowBuff n times
                    for(int x = 0; x < scale; x++)
                        rowBuff[curindex++] = triple;
                }
                curindex = 0;

                //for n times, write array to outfile and write outfile padding
                for (int x = 0; x < scale; x++)
                {
                    fwrite(rowBuff, rowsize, 1, outptr);
                    for (int k = 0; k < padding; k++)
                    {
                        fputc(0x00, outptr);
                    }
                }

                // skip over INFILE padding, if any
                fseek(inptr, origPadding, SEEK_CUR);
            }

            // close infile
            fclose(inptr);

            // close outfile
            fclose(outptr);

            free(rowBuff);
            // success
            return 0;
        }
