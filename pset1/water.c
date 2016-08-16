#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int time,total_water,bottles,cap_bot=16,ounce,oun_gall=128;
    float speed=1.5;
    printf("minutes: ");  //flow-time
    time=GetInt();
    ounce=speed*oun_gall;//per minute how many ounce
    total_water=time*ounce;//total water
    bottles=total_water/cap_bot;
    printf("bottles: %i",bottles);
    return 0;
}
    
    