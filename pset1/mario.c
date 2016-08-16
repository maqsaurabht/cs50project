#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int n,i,j,k;
    
    do
    {
      printf("height: ");
      n=GetInt();   
    }while(!((n>=0)&&(n<24)));
   
    for(i=0;i<n;i++)
    {
         for(k=n-i-1;k>0;k--)
        {
                printf(" ");
        }
        for(j=0;j<i+1;j++)
        {
           
           printf("#"); 
        }
        printf("#\n");
    }
   return 0; 
}