#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int i, length, length1, j;
        // convert string argument to integer key
        length1 = strlen(argv[1]);
        string key = argv[1];
       
        int k[length1];
        for (i = 0;i < length1;i++)
        {
            if (!isalpha(key[i]))
            {
                printf("Keyword must only contain letters A-Z and a-z\n");
                return 1;
            }
           
            
            if (islower( key[i]))
            {
                k[i] = ((int) key[i]) - 97;
            }
             
            else  if (isupper(key[i]))
            {
                k[i] = ((int) key[i]) - 65;
            }
             
             else
            {
                k[i] = key[i];
            }
            
        }
        // enter plain text
        string plain_text = GetString();
        length = strlen(plain_text);
        // array of cipher text
        char cipher_text[length];
        
        for(i = 0,j = 0;i < length;i++)
        {
            // for lowercase letter
            if (( plain_text[i] > 96) && ( plain_text[i] < 123))
            {
                cipher_text[i] = (((((int) plain_text[i]) - 97 + k[j]) % 26) + 97);
                j++;
            }
            // for uppercase letter
            else if (( plain_text[i] > 64) && ( plain_text[i] < 91))
            {
                cipher_text[i] = (((((int) plain_text[i]) - 65 + k[j]) % 26) + 65);
                j++;
            }
            // for other symbol
            else
            {
                cipher_text[i] = plain_text[i];
            }
            if (j == length1)
            {
                j = 0;
            }
        }
        // null character to terminate string
        cipher_text[length] = '\0';
        printf("%s\n",cipher_text);
        return 0;
    }
    else
    {   
        printf ("usage : ./caesar + key \n");
        return 1;
    }
    
}
    