/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include "dictionary.h"

FILE* fp;
int count=0;
char word[LENGTH+1];
 struct node
{
    char *word;
    struct node* next;
};
struct node* table[1024];
int hash_fn(const char* word)
{
     int len = strlen(word);
    int n = 0;

    for(int i = 0; i < len; i++)
    {
        int ch = word[i];
        if (ch >=65 && ch <= 90)
        {
            n += word[i] + 32;
        }
        else
        {
            n += word[i];
        }
    }
    
    return n % 1024; 
}
void display()
{
   struct node *p;
   for(int i=0;i<1024;i++)
   {
       p=table[i];
       while(p!=NULL)
       {
           printf("%s %d",p->word,i);
           p=p->next;
           printf("\n");
       }
   }
}
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int n=hash_fn(word);
    //printf("%d%s",n,word);
    struct node *p;
    p=table[n];
    while(p!=NULL)
       {
          if(strcasecmp(p->word,word)==0)
          {
             return true; 
          }
          p=p->next;
       }
    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    //char a[50];
    //char ch;
    fp=fopen(dictionary,"r");
    //printf("hello");
    if(fp==NULL)
    {
        printf("file can not opened");
    }
    for(int i=0;i<1024;i++)
    {
        table[i]=NULL;
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s",word);
        
        
        int n=hash_fn(word);
        //printf("%d",n);
        count++;
        struct node *temp=NULL;
        temp=malloc(sizeof(struct node));
        temp->word=malloc(strlen(word)+1);
        
        strcpy(temp->word,word);
        temp->next=NULL;
        if(table[n]==NULL)
        {
        table[n]=temp;
       
        }
        else
        {
            struct node *p;
            p=table[n];
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
            
        }
        
    } 
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    
    return count-1;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    struct node *p,*q;
   for(int i=0;i<1024;i++)
   {
       p=table[i];
       while(p!=NULL)
       {
           q=p;
           p=p->next;
           table[i]=p;
           free(q->word);
           free(q);
           
          
       }
       table[i]=NULL;
   }
    return true;
}
