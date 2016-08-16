/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
    FILE* fp;
    FILE* fs[50];
    int count=0;
    unsigned char buffer[512];
    char jpgname[20];
    fp=fopen("card.raw","rb");  
    //char ch;
    if(fp==NULL)
    {
        printf("can not open file");
    }
    int i=-1;
    
             
    while((fread(buffer,sizeof(buffer),1,fp))!=0)
    {
            
        if((buffer[0]==0xff)&&(buffer[1]==0xd8)&&(buffer[2]==0xff)&&((buffer[3]==0xe0)||(buffer[3]==0xe1)))
        {
            count++; 
            i++;
            sprintf(jpgname,"%03d.jpg",i);
               
            if(i>0)
            {
                fclose(fs[i-1]);
            } 
               
            fs[i]=fopen(jpgname,"w");
            fwrite(buffer,sizeof(buffer),1,fs[i]);  
              
        }
            
        else      
        {
            if(count>0)
            {
                fwrite(buffer,sizeof(buffer),1,fs[i]);
            }
                              
                            
        }
            
           
    }
     
    
    fclose(fp);
    return 0;
     
}
