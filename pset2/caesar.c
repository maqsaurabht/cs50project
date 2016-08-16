#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int i, length;
        // convert string argument to integer key
        int k = atoi(argv[1]); 
        // enter plain text
        string plain_text=GetString();
        length = strlen(plain_text);
        char cipher_text[length];
        for(i = 0;i < length;i++)
        {
            // for lowercase letter
            if (( plain_text[i] > 96) && ( plain_text[i] < 123))
            {
                cipher_text[i] = (((((int) plain_text[i]) - 97 + k) % 26) + 97);
            }
            // for uppercase letter
            else if (( plain_text[i] > 64) && ( plain_text[i] < 91))
            {
                cipher_text[i] = (((((int) plain_text[i]) - 65 + k) % 26) + 65);
            }
            // for other symbol
            else
            {
                cipher_text[i] = plain_text[i];
            }
        }
        printf("%s\n",cipher_text);
        return 0;
    }
    else
    {   
        printf ("usage : ./caesar + key \n");
        return 1;
    }
    
}
    