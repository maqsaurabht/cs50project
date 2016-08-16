/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int left=0,right=n-1;
    
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(values[mid]>value)
        {
            right=mid-1;
        }
        else  if(values[mid]<value)
        {
            left=mid+1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(values[min]>values[j])
            min=j;
        }
        if(min!=i)
        {
            int temp=values[min];
            values[min]=values[i];
            values[i]=temp;
        }
    }
    
    return;
}