/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // It is working if the number of arguments are 2 or 3.
    // otherwise print massage and program terminates.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // argv[1] takes the number of random numbers to be generate.
    // But it is string ,so we convert into integer.
    int n = atoi(argv[1]);

    // if the arv[2] is not null then if loop will be executed or else will be executed.
    // if the number(seed value) is same then it always print the same set of random number.
    // In else condition we use time ,since time is always changes ,so arguement of srand48 always change.
    // And we get truly random numbers each time.
    
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // drand48 generates a floating point between [0.0 ,1.0) 
    // it is multiplied by LIMIT the value is float ,which is converted into integer by typecasting. 
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}