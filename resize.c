#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"




int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: copy infile outfile\n");
        return 1;
    }
    
    // resize factor and filenames
    int n = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];
    
    if (n < 0 || n > 100)
    {
        printf("enter number between 1 and 100 only!\n");
    }
    
    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
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
        return 4;
    }
    
    // set new dimension for bitmap & calculate 
    int sWidth = bi.biWidth;
    int sHeight = bi.biHeight; 
    bi.biWidth =bi.biWidth* n;
    bi.biHeight =bi.biHeight* n;
    
    // padding for scanlines
    int sPadding = (4 - (sWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int lPadding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // calculation of bfSize
    bi.biSizeImage = abs(bi.biHeight) * (bi.biWidth * sizeof(RGBTRIPLE) + lPadding);
    bf.bfSize = (bi.biSizeImage + 54);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    
    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
        
    // iterate over infile's scanlines
    for (int i = 0; i < abs(sHeight); i++)
    {
        for (int b = 1; b <= n; b++)
        {   
            
            fseek(inptr, (54 + ((sWidth * 3 + sPadding) * i)), SEEK_SET);
            for (int j = 0; j < sWidth; j++)
            {
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                for (int m = 0; m < n; m++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }                   
            }
            
            
            for (int l = 0; l < lPadding; l++)
            {
                fputc(0x00, outptr);
            }
            
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}