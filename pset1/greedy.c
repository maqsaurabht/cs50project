#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
   int money2,count=0;
   float money,money1;
   do{
   printf("O hai! How much change is owed?\n");
   money=GetFloat();
   }
   while(money<0);
   money1=money*100;
   money2=round(money1);
  
   
   count=count+money2/25;
   money2=money2%25;
   count=count+money2/10;
   money2=money2%10;
   count=count+money2/5;
   money2=money2%5;
   count=count+money2/1;
    printf("%d\n",count);
   
   
    
   return 0;
}