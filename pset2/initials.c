#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name;                  
    int i, length;
    // Enter the name 
    name = GetString();  
    // convert the first character into upper case
    if (islower(name[0]))
    {
        name[0] = name[0] - 32;   
    }
    printf("%c" , name[0]);
    // length denotes the length of string provided by user
    for (i = 1 , length = strlen(name);i < length;i++)  
    {
        if (name[i] == ' ')
        {
         // convert lower case to upper case
            if (islower(name[i + 1]))
            {
                name[i + 1] = name[i + 1] - 32;              
                printf("%c",name[i + 1]);
            }
            else
            {
                printf("%c",name[i + 1]);   
            }

        }
     
    }
    printf("\n");
    return 0;
}    
    